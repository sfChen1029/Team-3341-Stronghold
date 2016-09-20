#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class DriveTrain: public Subsystem
{
    private:
        int ticksToDistance;
        float mult;

        Talon* left;
        Talon* right;
        Encoder* encoderLeft;
        Encoder* encoderRight;
        BuiltInAccelerometer* accel;
        AnalogGyro* gyro;

    public:
        DriveTrain();
        ~DriveTrain();

        static float Limit(float num, float max);

        void setMult(float m);
        int getMult();
        void arcadeDrive(float move, float rotate);

        double getDistance();
        double getRate();
        void resetEncoders();
        void getAccelerations(double* x, double* y, double* z);

        double getRightEncoderDistance();
        double getLeftEncoderDistance();

        double getGyroAngle();
        void resetGyro();

        void InitDefaultCommand();
};

#endif

