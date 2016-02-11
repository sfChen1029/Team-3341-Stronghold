#ifndef StopAcquirer_H
#define StopAcquirer_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopAcquirer: public CommandBase
{
    public:
        StopAcquirer();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();
};

#endif
