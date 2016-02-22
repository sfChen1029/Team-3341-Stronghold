#ifndef Drive_H
#define Drive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem
{
    private:
        Talon* left;
        Talon* right;
        Encoder* encoderLeft;
        Encoder* encoderRight;

        float mult; // Motor speed multiplier
        bool isUsingRotationCurve; // Enables Cubic Curve Control for steering

    public:
        Drive();

        static float Limit(float num, float max);

        void toggleRotationCurve();
        bool usingRotationCurve();
        void setMult(float m);
        void arcadeDrive(float move, float rotate);

        double GetDistance();
        double GetRate();
        void ResetEncoders();

        void InitDefaultCommand();
};

#endif

