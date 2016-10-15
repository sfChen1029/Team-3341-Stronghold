#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm() :
		Subsystem("Arm"), armOn(false), armMotor(new Jaguar(ARM)), armGyro(
				new Gyro(1)) {

}
Arm::~Arm() {
	delete armMotor;
	delete armGyro;
	armMotor = NULL;
	armGyro = NULL;
}
void Arm::ArmUp() {
	armMotor->SetSpeed(0.8);
}
void Arm::ArmDown() {
	armMotor ->SetSpeed(-0.8);
}
void Arm::StopArm() {
	armMotor ->SetSpeed(0);
}
void Arm::ArmOn() {
	armOn = true;
}
void Arm::ArmOff() {
	armOn = false;
}
double Arm::getAngle() {
	return armGyro->GetAngle();
}
void Arm::setAngle(double angle) {
	if (armGyro->GetAngle()<angle){
		while(armGyro->GetAngle()<angle){
			armMotor->SetSpeed(0.5);
		}
		armMotor->SetSpeed(0);
	}
	else if (armGyro->GetAngle()>angle){
		while(armGyro->GetAngle()>angle){
			armMotor->SetSpeed(-0.5);
		}
		armMotor->SetSpeed(0);
	}
}
void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
