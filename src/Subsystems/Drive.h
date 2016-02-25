#ifndef Drive_H
#define Drive_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class Drive: public Subsystem
{
    private:
        Talon* left;
        Talon* right;
        Encoder* encoderLeft;
        Encoder* encoderRight;

        float mult; // Motor speed multiplier TODO: make cubic control for driving as well

    public:
        Drive();

        static float Limit(float num, float max);

        void setMult(float m);
        int getMult();
        void arcadeDrive(float move, float rotate);

        double GetDistance();
        double GetRate();
        void ResetEncoders();
        void getAccelerations(double* x, double* y, double* z);

        void InitDefaultCommand();
};

#endif

