#ifndef GyroSubsystem_H
#define GyroSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class GyroSubsystem: public Subsystem
{
    private:
        Gyro* gyro;
    public:
        GyroSubsystem();
        void InitDefaultCommand();
        double GetAngle();
        void ResetGyro();
};

#endif
