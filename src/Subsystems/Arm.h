#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

/*
    Components:
    * Encoder
    * Motor
    * Limit Switch (2)

    Functionality:
    * armUp - rotates arm up to the robots and stops (attach to button)
    * setStart - puts arm in start (neutral) position (attach to button)
    * armDown - rotates arm down (for see-saw obstacle; attach to button)
    * rotateUpWhileTriggered (can be “triggered” by either button or joystick)
    * rotateDownWhileTriggered (can be “triggered” by either button or joystick)
    * StopArm - Called either based on limit switch input or button input
*/

class Arm: public Subsystem
{
    private:
        Jaguar* motor;
        Encoder* encoder;
        float speed;
        bool armControl;
    public:
        float const static DEFAULT_SPEED;
        Arm();
        void ArmOn();
        void ArmOff();
        void MoveArm(float speed);
        void SetStart();
        void StopArm();
        void InitDefaultCommand();
        double GetAngle();
};

#endif
