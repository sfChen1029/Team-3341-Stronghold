#ifndef SetDirectionReverse_H
#define SetDirectionReverse_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetDirectionReverse: public CommandBase
{
    public:
        SetDirectionReverse();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
