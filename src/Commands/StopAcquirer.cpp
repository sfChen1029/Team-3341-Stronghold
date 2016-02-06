#include "StopAcquirer.h"

StopAcquirer::StopAcquirer()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void StopAcquirer::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StopAcquirer::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopAcquirer::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StopAcquirer::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopAcquirer::Interrupted()
{

}
