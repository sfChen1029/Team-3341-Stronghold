#include "Commands/TurnAndDrive.h"
#include <Commands/LowBarAutonomous.h>

LowBarAutonomous::LowBarAutonomous() :
    zf(0), zi(0), xinit(0), yinit(0), zinit(0),
    driveDistance(new TurnAndDrive(6.0, 0.0))
{
    mode = breachModes::BREACHINGLOWBAR;
    Requires(drive);
    up = false;
    upndown = false;
}

void LowBarAutonomous::Initialize()
{
    drive->ResetEncoders();
    drive->getAccelerations(&xinit, &yinit, &zinit);
}

void LowBarAutonomous::Execute()
{
    switch(mode)
    {
        case breachModes::BREACHINGLOWBAR:
            breachLowBar();
            break;
        case breachModes::WALLFOLLOWING:
            followWall();
            break;
    }
}

void LowBarAutonomous::breachLowBar()
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
        mode = breachModes::AUTONOMOUSDONE;
    }
}

void LowBarAutonomous::followWall()
{
    driveDistance->Execute();

    if(driveDistance->IsFinished())
        mode = breachModes::AUTONOMOUSDONE;
}

bool LowBarAutonomous::IsFinished()
{
    return mode == breachModes::AUTONOMOUSDONE;
}

void LowBarAutonomous::End()
{
    std::cout << "Done!" << std::endl;
    drive->arcadeDrive(0, 0);
}

void LowBarAutonomous::Interrupted()
{
}
