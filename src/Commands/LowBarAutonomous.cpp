#include <Commands/LowBarAutonomous.h>

LowBarAutonomous::LowBarAutonomous()
{
    Requires(drive);
    up = false;
    upndown = false;

    xinit = 0;
    yinit = 0;
    zinit = 0;
    zf = 0;
}

void LowBarAutonomous::Initialize()
{
    std::cout << "Initializing autonomous mode" << std::endl;
    drive->getAccelerations(&xinit, &yinit, &zinit);
    zf = -2147483647;
}

void LowBarAutonomous::Execute()
{
    drive->getAccelerations(&xinit, &yinit, &zinit);
    drive->arcadeDrive(1, 0);

    if(yinit > 0.15)
        up = true;
    else if(up && yinit < 0.03)
        upndown = true;

    if(zf % 50 == 0)
        std::cout << xinit << " " << yinit << " " << zinit << std::endl;

    zf++;
}

bool LowBarAutonomous::IsFinished()
{
    return upndown || zf < 2147483647;
}

void LowBarAutonomous::End()
{
    std::cout << "Done!" << std::endl;
}

void LowBarAutonomous::Interrupted()
{
}
