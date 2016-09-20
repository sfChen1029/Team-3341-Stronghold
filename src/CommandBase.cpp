#include "CommandBase.h"
#include "Commands/Scheduler.h"

DriveTrain* CommandBase::drive = NULL;
OI* CommandBase::oi = NULL;
GyroSubsystem* CommandBase::gyro = NULL;
Intake* CommandBase::intake = NULL;
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
    drive = new DriveTrain();
    oi = new OI();
    gyro = new GyroSubsystem();
	intake = new Intake();
    arm = new Arm();
}
