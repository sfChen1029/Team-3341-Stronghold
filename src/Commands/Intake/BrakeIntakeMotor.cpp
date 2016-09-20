#include "BrakeIntakeMotor.h"
#include "CommandBase.h"

BrakeIntakeMotor::BrakeIntakeMotor()
{
    Requires(intake);
}

void BrakeIntakeMotor::Initialize()
{
}

void BrakeIntakeMotor::Execute()
{
    intake->Stop();
}

bool BrakeIntakeMotor::IsFinished()
{
    return true;
}

void BrakeIntakeMotor::End()
{
    intake->Disable();
}

void BrakeIntakeMotor::Interrupted()
{
}
