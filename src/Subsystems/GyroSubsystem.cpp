#include "GyroSubsystem.h"
#include "../RobotMap.h"

GyroSubsystem::GyroSubsystem() :
    Subsystem("GyroSubsystem")
{
    agyro = new Gyro(new AnalogInput(0));
    agyro->InitGyro();
    agyro->Reset();
}

void GyroSubsystem::InitDefaultCommand()
{
}

double GyroSubsystem::GetAngle()
{
    return -agyro->GetAngle();
}

void GyroSubsystem::ResetGyro()
{
    agyro->Reset();
}
