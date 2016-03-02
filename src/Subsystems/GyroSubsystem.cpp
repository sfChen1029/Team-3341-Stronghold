#include "GyroSubsystem.h"
#include "../RobotMap.h"

GyroSubsystem::GyroSubsystem() :
    Subsystem("GyroSubsystem")
{

    gyro = new AnalogGyro(0);
    gyro->Calibrate();
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
