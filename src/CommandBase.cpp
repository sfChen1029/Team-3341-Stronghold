#include "CommandBase.h"
#include "Commands/Scheduler.h"

DriveTrain* CommandBase::drive = NULL;
OI* CommandBase::oi = NULL;


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

}
