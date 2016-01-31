#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar* motor;
	Encoder* encoder;
public:
	Arm();
	void InitDefaultCommand();
};

#endif
