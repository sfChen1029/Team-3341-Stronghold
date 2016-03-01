#ifndef BreachDefense_H
#define BreachDefense_H

#include "../CommandBase.h"
#include "Commands/TurnAndDrive.h"
#include "WPILib.h"
//#include "GyroSubsystem.h"

class LowBarAutonomous: public CommandBase
{
    public:
        LowBarAutonomous();
        void Initialize();
        void Execute();bool IsFinished();
        void End();
        void Interrupted();

    private:
        // consts for different sections of autonomous mode
        enum breachModes {BREACHINGLOWBAR = 0, WALLFOLLOWING, AUTONOMOUSDONE};

        bool up, upndown;
        double xinit, yinit, zinit;
        int zf, zi;
        int mode;

        TurnAndDrive* driveDistance;

        void breachLowBar();
        void followWall();
};

#endif
