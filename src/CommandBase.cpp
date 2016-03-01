#include "CommandBase.h"
#include "Commands/Scheduler.h"

Drive* CommandBase::drive = NULL;
OI* CommandBase::oi = NULL;
GyroSubsystem* CommandBase::gyro = NULL;
UltrasonicSensors* CommandBase::ultraSonic = NULL;
Acquirer* CommandBase::acquirer = NULL;
Arm* CommandBase::arm = NULL;

CommandBase::CommandBase(char const* name) :
    Command(name)
{
}

CommandBase::CommandBase() :
    Command()
{
}

void CommandBase::init()
{
    drive = new Drive();
    oi = new OI();
    gyro = new GyroSubsystem();
	ultraSonic = new UltrasonicSensors();
	acquirer = new Acquirer();
    arm = new Arm();
}
