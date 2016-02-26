#ifndef Acquirer_H
#define Acquirer_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Acquirer: public Subsystem
{
    private:
        Jaguar* motor;
        bool enabled;
        AnalogInput* ir;
        int THRESHOLD;

    public:
        Acquirer();
        void BallIn();
        void BallOut();
        void Stop();
        bool IsEnabled();
        void Enable();
        void Disable();
        bool DetectBall();
        double GetInput();
};

#endif
