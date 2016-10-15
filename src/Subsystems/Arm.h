#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar* armMotor;
	Gyro* armGyro;
	bool armOn;
public:
	Arm();
	~Arm();
	void ArmUp();
	void ArmDown();
	void StopArm();
	void ArmOn();
	void ArmOff();
	double getAngle();
	void setAngle(double angle);
	void InitDefaultCommand();
};

#endif
