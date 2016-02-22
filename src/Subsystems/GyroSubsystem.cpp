#include "GyroSubsystem.h"
#include "../RobotMap.h"

GyroSubsystem::GyroSubsystem() :
    Subsystem("GyroSubsystem")
{
    gyro = new Gyro(new AnalogInput(GYROPIN));
    gyro->InitGyro();
    gyro->Reset();
}

void GyroSubsystem::InitDefaultCommand()
{
}

double GyroSubsystem::GetAngle()
{
    return -gyro->GetAngle();
}

void GyroSubsystem::ResetGyro()
{
    gyro->Reset();
}
