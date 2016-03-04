#ifndef GetBall_H
#define GetBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class GetBall: public CommandBase
{
    private:
        bool isEmergency;
    public:
        GetBall(bool _isEmergency = false);
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
