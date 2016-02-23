#include "StopArm.h"
#include "CommandBase.h"

StopArm::StopArm()
{
    Requires(arm);
}

void StopArm::Initialize()
{
}

void StopArm::Execute()
{
    arm -> StopArm();
}

bool StopArm::IsFinished()
{
    return true;
}

void StopArm::End()
{
}

void StopArm::Interrupted()
{
}
