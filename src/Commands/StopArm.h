#ifndef StopArm_H
#define StopArm_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopArm: public CommandBase
{
    public:
        StopArm();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
