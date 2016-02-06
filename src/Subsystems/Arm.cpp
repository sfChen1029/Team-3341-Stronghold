#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() :
		Subsystem("Arm")
{
	armControl = false;
	encoder = new Encoder(ENCODER_LEFT_1,ENCODER_LEFT_2);
	motor = new Jaguar(DRIVE_LEFT);
	speed = 0;

	encoder->Reset();
	encoder->SetDistancePerPulse(1); // set based on experimentation
}

void Arm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Arm::MoveArm(float speed)
{
	if(armControl)
	motor->Set(speed);
}

void Arm::StopArm()
{
	motor->Set(0);
}

void Arm::ArmOff()
{
	this->armControl = false;
}

void Arm::ArmOn()
{
	this->armControl = true;
}

void Arm::SetStart()
{
	ArmOn();
	while(this->GetAngle() > 5)
	{
		this->MoveArm(-0.5);
	}
	ArmOff();
}

double Arm::GetAngle()
{
	return encoder->GetDistance();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
