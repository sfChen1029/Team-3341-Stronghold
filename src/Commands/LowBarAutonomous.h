#ifndef BreachDefense_H
#define BreachDefense_H

#include "../CommandBase.h"
#include "WPILib.h"

class LowBarAutonomous: public CommandBase
{
    public:
        LowBarAutonomous();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();

    private:
        bool up, upndown;
        double xinit, yinit, zinit;
        int zf;
};

#endif
