#include "MoatRun.h"
#include "TurnAndDrive.h"

MoatRun::MoatRun()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
    drive = new TurnAndDrive(70, 0);
}

// Called just before this Command runs the first time
void MoatRun::Initialize()
{

    drive->Start();
    SetTimeout(4);
}

// Called repeatedly when this Command is scheduled to run
void MoatRun::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool MoatRun::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void MoatRun::End()
{
    drive->ForceFinish();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoatRun::Interrupted()
{

}
