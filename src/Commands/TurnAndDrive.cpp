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
    anglePid = new NewPIDController(0.1, 1e-2, 0, angle, false);
}

void TurnAndDrive::Execute()
{
    //gyro->ResetGyro();
    double current_distance = drive->GetDistance();
    double pwm_val = distancePid->Tick(current_distance);
    double current_angle = gyro->GetAngle();
    double rotateVal = anglePid->Tick(current_angle);

    std::cout << "rotateVal: " << rotateVal;

    std::cout << "Gyro PV: " << current_angle << std::endl;
    std::cout << "Gyro error: " << anglePid->GetError() << std::endl;

    drive->arcadeDrive(Drive::Limit(pwm_val, 0.7), Drive::Limit(rotateVal, 1.0));
}

bool TurnAndDrive::IsFinished()
{
    bool finished =
    (
        (
            (fabs(distancePid->GetError()) < 0.005)
            && (fabs(anglePid->GetError()) < 0.01)
            //&& (fabs(drive->GetRate()) < 1e-3)
        )
    );
    if(finished) std::cout << "Autonomous finished" << std::endl;
    return finished;
}

void TurnAndDrive::End()
{
    drive->arcadeDrive(0, 0);
}

void TurnAndDrive::Interrupted()
{
}
