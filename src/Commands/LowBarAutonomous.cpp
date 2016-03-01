#include "Commands/TurnAndDrive.h"
#include <Commands/LowBarAutonomous.h>

LowBar::LowBar() :
    zf(0), zi(0), xinit(0), yinit(0), zinit(0),
    driveDistance(new TurnAndDrive(6.0, 0.0)),
    BREACHINGLOWBAR(0), WALLFOLLOWING(1), AUTONOMOUSDONE(3)
{
    mode = BREACHINGLOWBAR;
    Requires(drive);
    up = false;
    upndown = false;
}

void LowBar::Initialize()
{
    drive->ResetEncoders();
    std::cout << "iiiiiiiinnnnnnnniiiiiiitttttt" << std::endl;
    drive->getAccelerations(&xinit, &yinit, &zinit);
}

void LowBar::Execute()
{
    switch(mode)
    {
        // TODO: BAD STYLE, GET THE CONSTANTS TO WORK
        case 0:
            breachLowBar();
            break;
        case 1:
            followWall();
            break;
    }
}

void LowBar::breachLowBar()
{
    drive->getAccelerations(&xinit, &yinit, &zinit);
    drive->arcadeDrive(0.15, 0);
    if (zinit > 1.5 || zinit < 0.5)
    {
        int i = zf;
        zi = i;
        if (up)
            upndown = true;
    }
    if (!up)
    {
        if (zf - zi >= 50)
            up = true;
    }
    std::cout << xinit << " " << yinit << " " << zinit << std::endl;
    zf++;

    // Finished breaching low bar, now follow the wall
    if(upndown || zf > 2000000)
    {
        drive->ResetEncoders();
        // TODO: switch AUTONOMOUSDONE to WALLFOLLOW once BREACHLOWBAR works
        mode = AUTONOMOUSDONE;
    }
}

void LowBar::followWall()
{
    driveDistance->Execute();

    if(driveDistance->IsFinished())
        mode = AUTONOMOUSDONE;
}

bool LowBar::IsFinished()
{
    return mode == 3;
}

void LowBar::End()
{
    std::cout << "Done!" << std::endl;
    drive->arcadeDrive(0, 0);
}

void LowBar::Interrupted()
{
}
