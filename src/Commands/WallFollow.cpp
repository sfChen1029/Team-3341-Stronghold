#include "WallFollow.h"
#include "ArcadeDrive.h"

WallFollow::WallFollow()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ultraSonic);
	Requires(drive);
	this->DISTANCE_FROM_WALL = 200;
	this->DISTANCE_TO_TARGET = 200;
	this->DRIVE_SPEED = 0.1;

	double kp = 0.0001;
	double ki = 0.0001;
	double kd = 0;
	int setpoint = this->DISTANCE_FROM_WALL;
	bool integralThreshold = false;
	pid = new NewPIDController(kp,ki,kd,setpoint,integralThreshold);
}

// Called just before this Command runs the first time
void WallFollow::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WallFollow::Execute()
{
	double tickedRotValue = pid->Tick(ultraSonic->ReadUltra(UltraSoundTester::RIGHTSENSOR));
    drive->arcadeDrive(this->DRIVE_SPEED, tickedRotValue);
}

// Make this return true when this Command no longer needs to run execute()
bool WallFollow::IsFinished()
{
	return drive->GetDistance() < this->DISTANCE_TO_TARGET;
}

// Called once after isFinished returns true
void WallFollow::End()
{
	delete pid;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WallFollow::Interrupted()
{

}
