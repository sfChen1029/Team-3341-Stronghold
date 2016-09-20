#ifndef IntakeBall_H
#define IntakeBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeBall: public CommandBase
{
    private:
        bool isEmergency;
    public:
        IntakeBall(bool _isEmergency = false);
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
