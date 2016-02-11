#ifndef Acquirer_H
#define Acquirer_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Acquirer: public Subsystem
{
    public:
        Acquirer();
        void InitDefaultCommand();
};

#endif
