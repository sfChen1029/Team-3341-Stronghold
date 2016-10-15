#include "IntakeBall.h"
#include "CommandBase.h"
//#include "Intake.h"

IntakeBall::IntakeBall()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intake);
}

// Called just before this Command runs the first time
void IntakeBall::Initialize()
{
	intake->Enable();
}

// Called repeatedly when this Command is scheduled to run
void IntakeBall::Execute()
{
	intake->BallIn();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeBall::IsFinished()
{
	return !intake->IsEnabled;
}

// Called once after isFinished returns true
void IntakeBall::End()
{
	intake->Stop();
	intake->Disable();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeBall::Interrupted()
{

}
