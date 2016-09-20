#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
    private:
        Talon* motor;
        AnalogInput* ir;

        bool enabled;
        int THRESHOLD;

    public:
        Intake();
        ~Intake();

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
