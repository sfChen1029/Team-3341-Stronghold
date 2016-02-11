#ifndef GetBall_H
#define GetBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class GetBall: public CommandBase
{
    public:
        GetBall();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
