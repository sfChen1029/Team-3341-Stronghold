#ifndef ReadLeftUltra_H
#define ReadLeftUltra_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReadLeftUltra: public CommandBase
{
    public:
        ReadLeftUltra();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
