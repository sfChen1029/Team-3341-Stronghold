#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	Talon* intakeMotor;// intake motor
	AnalogInput* ir;//ir sensor

	bool enabled; //if motor is enabled

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Intake();
	~Intake();
	//void InitDefaultCommand();//don't need because intake doesn't need joystick

	void BallIn();
	void BallOut();
	void Stop(); //stops motors
	bool isEnabled(); //returns enabled
	void Enable();
	void Disable();
	bool DetectBall();
	double getInput();

};

#endif
