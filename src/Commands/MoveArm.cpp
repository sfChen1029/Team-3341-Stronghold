#include "MoveArm.h"
#include "CommandBase.h"

MoveArm::MoveArm()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);'
	Requires(arm);
}

// Called just before this Command runs the first time
void MoveArm::Initialize()
{
	arm->armOn();
}

// Called repeatedly when this Command is scheduled to run
void MoveArm::Execute()
{
	arm->ArmUp();
	arm->StopArm();
	arm->ArmDown();
	arm->StopArm();
	arm->setAngle(40);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished()
{

	return !arm->armOn;
}

// Called once after isFinished returns true
void MoveArm::End()
{
	arm->StopArm();
	arm->armOff();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveArm::Interrupted()
{

}
