#include "BrakeIntakeMotor.h"
#include "CommandBase.h"

BrakeIntakeMotor::BrakeIntakeMotor()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intake);
}

// Called just before this Command runs the first time
void BrakeIntakeMotor::Initialize()
{
	intake->Enable();
}

// Called repeatedly when this Command is scheduled to run
void BrakeIntakeMotor::Execute()
{
	intake->Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool BrakeIntakeMotor::IsFinished()
{
	return !intake->IsEnabled;;
}

// Called once after isFinished returns true
void BrakeIntakeMotor::End()
{
	intake->Stop();
	intake->Disable();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BrakeIntakeMotor::Interrupted()
{

}
