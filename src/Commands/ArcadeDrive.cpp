#include "ArcadeDrive.h"

ArcadeDrive::ArcadeDrive()
    : isReset(true)
{
    Requires(drive);
    Requires(gyro);
}

void ArcadeDrive::Initialize()
{
    gyro->ResetGyro();
    anglePid = new NewPIDController(.05, 0, 0, 0, false);
}

void ArcadeDrive::Execute()
{
    // Joystick is turning, turn normally
    if(fabs(oi->getDriveStick()->GetZ()) >= 0.05)
    {
        isReset = false;
        double x = oi->getDriveStick()->GetZ();
        double a = 0.7;
        double b = 0;
        double control;

        // Use Cubic Function to make turning more smooth if getRotationCurve() is true (can be disabled with joystick button)
        if(drive->getRotationCurve())
        {
            if(x > 0)
                control = b + (1 - b) * ((a * pow(x, 3) + (1 - a) * x));
            else
                control = -b + (1 - b) * ((a * pow(x, 3) + (1 - a) * x));
        }
        else
        {
            control = x;
        }

        drive->arcadeDrive(-oi->getDriveStick()->GetY(), -control);
    }
    else // Joystick is straight, use Gyro to drive straight
    {
    	double angle = gyro-> GetAngle();
    	double correctedAngleSignal = anglePid->Tick(angle);
    	drive -> arcadeDrive(.05, correctedAngleSignal);
        if(!isReset)
        {
            drive->arcadeDrive(0, 0);
            Wait(.05);
            isReset = true;
            gyro->ResetGyro();
        }

        // Feed the angle from the Gyro into the PID loop; use returned value from PID loop to drive straight
        if(fabs(oi->getDriveStick()->GetY()) >= .05)
        {
            drive->arcadeDrive(-oi->getDriveStick()->GetY(),
                               anglePid->Tick(gyro->GetAngle()));
        }
        else
        {
            // Brake the drive wheels
            drive->arcadeDrive(0, 0);
        }
    }
}

bool ArcadeDrive::IsFinished()
{
    return false;
}

void ArcadeDrive::End()
{
}

void ArcadeDrive::Interrupted()
{
}
