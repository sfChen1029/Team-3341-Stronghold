#include "OI.h"
#include "Commands/DriveReverse.h"
#include "Commands/DriveForward.h"
#include "Commands/ShootBall.h"
#include "Commands/StopAcquirer.h"
#include "Commands/GetBall.h"
#include "Commands/ToggleRotationCurve.h"
#include "CommandBase.h"

OI::OI() :
    driveStick(new Joystick(DRIVESTICK)), operatorStick(new Joystick(OPERATORSTICK))
{
    Button* driveTrigger = new JoystickButton(driveStick, 1);
    driveTrigger->WhenPressed(new DriveReverse());
    driveTrigger->WhenReleased(new DriveForward());

    Button* toggleRotationCurve = new JoystickButton(driveStick, 5);
    toggleRotationCurve->WhenPressed(new ToggleRotationCurve());

    Button* toggleReverse = new JoystickButton(driveStick, 13);
    toggleReverse->WhenPressed(new DriveReverse());

    Button* shootBall = new JoystickButton(operatorStick, 10);
    shootBall->WhenPressed(new ShootBall());
    shootBall->WhenReleased(new StopAcquirer());

    Button* getBall = new JoystickButton(operatorStick, 9);
    getBall->WhenPressed(new GetBall());
    getBall->WhenReleased(new StopAcquirer());

    Button* stopBall = new JoystickButton(operatorStick, 8);
    stopBall->WhenPressed(new StopAcquirer());
}

Joystick* OI::getDriveStick()
{
    return driveStick;
}

Joystick* OI::getOperatorStick()
{
    return operatorStick;
}
