#include <Commands/TurnAndDrive.h>
TurnAndDrive::TurnAndDrive(double inDistance, double inAngle)
    : distance(inDistance), angle(inAngle)
{
    Requires(drive);
    Requires(gyro);
    distancePid = NULL;
    anglePid = NULL;
}

void TurnAndDrive::Initialize()
{
    SetTimeout(2.2);
    drive->ResetEncoders();
    gyro->ResetGyro();
    distancePid = new NewPIDController(0.15, 0.0, 0.0, distance, false);
    anglePid = new NewPIDController(0.03, 1e-3, 0, angle, false);
}

void TurnAndDrive::Execute()
{
    gyro->ResetGyro();
    double current_distance = drive->GetDistance();
    double pwm_val = distancePid->Tick(current_distance);
    double current_angle = gyro->GetAngle();
    double rotateVal = anglePid->Tick(current_angle);

    printf("Distance setpoint: %f; Current distance: %f; Distance error: %f; Distance Last PWM: %f; Distance rate: %f\n",
           distancePid->GetSetPoint(), current_distance, distancePid->GetError(),
           distancePid->GetLastPWM(), drive->GetRate());

    drive->arcadeDrive(Drive::Limit(pwm_val, .5), Drive::Limit(rotateVal, 1.0));
}

bool TurnAndDrive::IsFinished()
{
    return 
    (
        (
            (fabs(distancePid->GetError()) < 0.005)
            && (fabs(anglePid->GetError()) < 0.5) 
            //&& (fabs(drive->GetRate()) < 1e-3)
        )
        || IsTimedOut()
    );
}

void TurnAndDrive::End()
{
    drive->arcadeDrive(0, 0);
}

void TurnAndDrive::Interrupted()
{
}

