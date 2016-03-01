#ifndef BreachDefense_H
#define BreachDefense_H

#include "../CommandBase.h"
#include "WPILib.h"
//#include "GyroSubsystem.h"

class LowBar: public CommandBase
{
    public:
        LowBar();
        void Initialize();
        void Execute();bool IsFinished();
        void End();
        void Interrupted();

    private:
        // consts for different sections of autonomous mode
        int BREACHINGLOWBAR;
        int WALLFOLLOWING;
        int AUTONOMOUSDONE;

        bool up, upndown;
        double xinit, yinit, zinit;
        int zf, zi;
        int mode;

        TurnAndDrive* driveDistance;

        void breachLowBar();
        void followWall();
};

#endif
