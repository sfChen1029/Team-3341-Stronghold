#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../AbsEncoder.h"

/*
    Components:
    * Encoder
    * Motor
    * Limit Switch (2)

    Functionality:
    * armUp - rotates arm up to the robots and stops (attach to button)
    * setStart - puts arm in start (neutral) position (attach to button)
    * armDown - rotates arm down (for see-saw obstacle; attach to button)
    * rotateUpWhileTriggered (can be â€œtriggeredâ€� by either button or joystick)
    * rotateDownWhileTriggered (can be â€œtriggeredâ€� by either button or joystick)
    * StopArm - Called either based on limit switch input or button input
*/

class Arm: public Subsystem
{
    private:
        Jaguar* motor;
       // AbsEncoder* encoder;
        float speed;
        bool armControl;

    public:
        Arm();
        ~Arm();

        float const static DEFAULT_SPEED;
        void ArmOn();
        void ArmOff();
        void moveArm(float speed); // changed name from "MoveArm" to "moveArm" to avoid conflict with Command Name
        void SetStart();
        void StopArm();
        short GetAngle();
        void SetAngle(double angle);
        void InitDefaultCommand();

};

#endif
