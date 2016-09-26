#ifndef SetDirectionForward_H
#define SetDirectionForward_H

#include "../../CommandBase.h"
#include "WPILib.h"

class SetDirectionForward: public CommandBase
{
    public:
        SetDirectionForward();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
