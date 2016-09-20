#include "LiftDoor.h"
#include "CommandBase.h"

LiftDoor::LiftDoor()
{
	Requires(arm);
}

// Called just before this Command runs the first time
void LiftDoor::Initialize()
{
	arm -> ArmOn();
	arm -> SetStart();
}

// Called repeatedly when this Command is scheduled to run
void LiftDoor::Execute()
{
	//arm -> SetAngle(DOOR_ANGLE);
	arm -> SetStart();
}

// Make this return true when this Command no longer needs to run execute()
bool LiftDoor::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LiftDoor::End()
{
	arm -> StopArm();
	arm -> ArmOff();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftDoor::Interrupted()
{

}
