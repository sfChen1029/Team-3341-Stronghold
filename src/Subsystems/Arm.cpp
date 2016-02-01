#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() :
		Subsystem("Arm")
{
	encoder = new Encoder(ENCODER_LEFT_1,ENCODER_LEFT_2);
	motor = new Jaguar(DRIVE_LEFT);
	speed = 0;
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Arm::MoveArm(float speed)
{
	motor->Set(speed);
}

void Arm::StopArm()
{
	motor->Set(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
