#include "OI.h"
#include "Commands/DriveReverse.h"
#include "Commands/DriveForward.h"
#include "Commands/TurnAndDrive.h"
#include "Commands/ShootBall.h"
#include "Commands/StopAcquirer.h"
#include "Commands/GetBall.h"
#include "CommandBase.h"

/*
 * DESCRIPTION:
 *
 * DRIVESTICK is used to drive robot and control drive functionality
 * via use of buttons
 * 		Buttons: Hold down button 13 to Drive Reverse
 * 				 Press button 5 to ToggleRotationCurve (Cubic vs Normal control)
 *
 * OPERATORSTICK is used to control the Arm via Joystick and
 * Acquirer via buttons
 * 		Buttons: Hold down button 10 to shoot ball
 * 				 Hold down button 9 to get ball
 * 				 Press button 8 to stop acquirer (in case of emergency)
 */
OI::OI() :
    driveStick(new Joystick(DRIVESTICK)), operatorStick(new Joystick(OPERATORSTICK))
{
    // Push button 16 once to make the robot turn 180 degrees
    //Button* turn180Button = new JoystickButton(driveStick, 16);
    //turn180Button->WhenPressed(new TurnAndDrive(0.0, 3.1415));

    // Hold down button 13 to "switch the front and back sides" of the robot
    // Make driving in reverse much easier
    Button* toggleReverse = new JoystickButton(driveStick, 13);
    toggleReverse->WhenPressed(new DriveReverse());
    toggleReverse->WhenReleased(new DriveForward());

    // Hold down trigger on drive stick to shoot ball
    

    // Hold down button 2 on drive stick to get ball
    // for right handed drivers


    // Hold down button 3 on drive stick to get ball
    // for right handed drivers
    

    // Hold down button 4 on drive stick to get ball
    // for left handed drivers
    

    // Hold down button 14 on drive stick to get ball IN EMERGENCY MODE
    

    // Hold down button 2 on operator stick to acquire ball
    // for operator (to help the driver focus more on driving)
    

    // Hold down button 3 on operator stick to acquire ball
    // for operator (to help the driver focus more on driving)
  

    // Hold down button 4 on operator stick to acquire ball
    // for operator (to help the driver focus more on driving)
   

    // Press button 8 on operator stick to stop Acquirer (in case of emergency)
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
