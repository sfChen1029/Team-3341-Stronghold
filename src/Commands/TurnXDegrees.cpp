#include "TurnXDegrees.h"
#include "TurnAndDrive.h"

TurnXDegrees::TurnXDegrees(double angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void TurnXDegrees::Initialize()
{
	TurnAndDrive* turnCommand = new TurnAndDrive(0, 10);
	turnCommand->Start();
}

// Called repeatedly when this Command is scheduled to run
void TurnXDegrees::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool TurnXDegrees::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void TurnXDegrees::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnXDegrees::Interrupted()
{

}
