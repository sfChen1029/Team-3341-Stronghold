#include "Arm.h"
#include "../RobotMap.h"
#include "Commands/MoveArm.h"

Arm::Arm() :
    Subsystem("Arm")
{
    armControl = false;
    //encoder = new Encoder(ENCODER_LEFT_1, ENCODER_LEFT_2);
    motor = new Jaguar(ARM);
    speed = 0;
    //Command* moveArm = new EjectBall();
    //this->SetDefaultCommand(new MoveArm());
    //encoder = new AbsEncoder();
   // this->SetDefaultCommand(new MoveArm());
}

void Arm::InitDefaultCommand()
{
    SetDefaultCommand(new MoveArm());
}

// changed name from "MoveArm" to "moveArm" to avoid conflict with Command Name
void Arm::moveArm(float speedo)
{
    //if(armControl)
    motor->SetSpeed(speedo);
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
        this->moveArm(-0.5);
    }
    ArmOff();
}

short Arm::GetAngle()
{
   // return encoder->getInput();
	return 0; // temporary code
}

void Arm::SetAngle(double angle)
{
    ArmOn();
    while(this-> GetAngle() < angle)
    {
        this->moveArm(0.5);
    }
    ArmOff();
}

Arm::~Arm()
{
    delete motor;
}
