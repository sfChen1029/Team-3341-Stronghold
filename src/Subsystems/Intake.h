#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
    private:
        Talon* motor;
        bool enabled;
        AnalogInput* ir;
        int THRESHOLD;

    public:
        Intake();
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
