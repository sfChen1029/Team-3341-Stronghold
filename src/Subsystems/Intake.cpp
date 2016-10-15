#include "Intake.h"
#include "../RobotMap.h"

Intake::Intake() :
		Subsystem("Intake") {
	intakeMotor = new Talon(INTAKE);
	enabled = false;
	ir = new AnalogInput(INTAKE_IR);
}

Intake::~Intake() {
	delete intakeMotor;
	delete ir;
	intakeMotor = NULL;
	ir = NULL;
}

void Intake::BallIn() {
	if (enabled) {
		intakeMotor->SetSpeed(0.6);
	}
}
void Intake::BallOut() {
	if (enabled) {
		intakeMotor->SetSpeed(-0.6);
	}

}
void Intake::Stop() { //stops motors
	intakeMotor->SetSpeed(0);
}
bool Intake::isEnabled() { //returns enabled
	return enabled;
}
void Intake::Enable() {
	enabled = true;
}
void Intake::Disable() {
	enabled = false;
}
bool Intake::DetectBall() {
	if (getInput() > 10) {
		return false;
	}
	return true;
}
double Intake::getInput() {
	return ir->GetValue();
}
/*void Intake::InitDefaultCommand()
 {
 // Set the default command for a subsystem here.
 //SetDefaultCommand(new MySpecialCommand());
 }*/

// Put methods for controlling this subsystem
// here. Call these from Commands.
