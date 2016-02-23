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
        double rotRaw = -oi->getDriveStick()->GetZ();
        double yRaw = -oi->getDriveStick()->GetY();

        // Map linear Y input to Cubic output
        double yAdjusted = mapToCubic(0.35, 0.05, yRaw);

        // Use Cubic Function to make turning more smooth if usingRotationCurve() is true (can be disabled with joystick button)
        double rotAdjusted;
        if(drive->usingRotationCurve())
        {
            rotAdjusted = mapToCubic(0.7, 0, rotRaw);
        }
        else
        {
            rotAdjusted = rotRaw;
        }
        
        drive->arcadeDrive(yAdjusted, rotAdjusted);
    }
    else // Joystick is straight, use Gyro to drive straight
    {
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

double ArcadeDrive::mapToCubic(double a, double b, double signal)
{
    double control;

    if(signal > 0)
        control = b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));
    else
        control = -b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));

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
