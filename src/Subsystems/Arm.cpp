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
    //Command* moveArm = new ShootBall();
    //this->SetDefaultCommand(new MoveArm());
    //encoder = new AbsEncoder();
}

void Arm::InitDefaultCommand()
{
    //this->SetDefaultCommand(new MoveArm());
}

void Arm::MoveArm(float speedo)
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
        this->MoveArm(-0.5);
    }
    ArmOff();
}

short Arm::GetAngle()
{
    return encoder->getInput();
}

void Arm::SetAngle(double angle)
{
    ArmOn();
    while(this-> GetAngle() < angle)
    {
        this->MoveArm(0.5);
    }
    ArmOff();
}

