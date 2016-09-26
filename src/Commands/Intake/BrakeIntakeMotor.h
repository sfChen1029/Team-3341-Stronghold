#ifndef BrakeIntakeMotor_H
#define BrakeIntakeMotor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class BrakeIntakeMotor: public CommandBase
{
    public:
        BrakeIntakeMotor();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
