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
    double rotRaw = oi->getDriveStick()->GetZ();
    double yRaw = oi->getDriveStick()->GetY();
    double yAdjusted = mapToCubic(0.35, 0, yRaw);

    // Joystick is turning, turn normally
    if(fabs(rotRaw) >= 0.05)
    {
        isReset = false;
        double rotAdjusted;

        // Use Cubic Function to make turning more smooth if usingRotationCurve() is true (can be disabled with joystick button)
        if(drive->usingRotationCurve())
        {
            rotAdjusted = mapToCubic(0.7, 0, rotRaw);
        }
        else
        {
            rotAdjusted = rotRaw;
        }

        drive->arcadeDrive(-yAdjusted, -rotAdjusted);
    }
    else // Joystick is straight, use Gyro to drive straight
    {
        // Reset the Gyro sensor once only
        if(!isReset)
        {
            drive->arcadeDrive(0, 0);
            Wait(.05);
            isReset = true;
            gyro->ResetGyro();
        }

    	double angle = gyro->GetAngle();
    	double correctedAngleSignal = anglePid->Tick(angle);
        // TODO: the line below was here, do we need it?
    	//drive->arcadeDrive(.05, correctedAngleSignal);

        // Feed the angle from the Gyro into the PID loop; use returned value from PID loop to drive straight
        if(fabs(yRaw) >= .05)
        {
            drive->arcadeDrive(-yAdjusted, correctedAngleSignal);
        }
        else
        {
            // Brake the drive wheels
            drive->arcadeDrive(0, 0);
        }
    }
}

// Takes an input signal and maps it to a cubic output (for more precise driving)
double ArcadeDrive::mapToCubic(double a, double b, double signal)
{
    double control;

    if(x > 0)
        control = b + (1 - b) * ((a * pow(x, 3) + (1 - a) * x));
    else
        control = -b + (1 - b) * ((a * pow(x, 3) + (1 - a) * x));

    return control;
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
