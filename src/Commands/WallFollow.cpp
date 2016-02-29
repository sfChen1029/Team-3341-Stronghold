#include "WallFollow.h"
#include "ArcadeDrive.h"

WallFollow::WallFollow()
{
    Requires(ultraSonic);
    Requires(drive);

    DISTANCE_FROM_WALL = 200;
    DISTANCE_TO_TARGET = 200;
    DRIVE_SPEED = 0.1;

    double kp = 0.0001;
    double ki = 0.0001;
    double kd = 0;
    int setpoint = DISTANCE_FROM_WALL;
    bool integralThreshold = false;
    wallDistPID = new NewPIDController(kp, ki, kd, setpoint, integralThreshold);
}

void WallFollow::Initialize()
{
}

void WallFollow::Execute()
{
    double tickedRotValue = wallDistPID->Tick(
            ultraSonic->ReadUltra(UltraSoundTester::RIGHTSENSOR));
    drive->arcadeDrive(DRIVE_SPEED, tickedRotValue);
}

bool WallFollow::IsFinished()
{
    return drive->GetDistance() < DISTANCE_TO_TARGET;
}

void WallFollow::End()
{
    delete wallDistPID;
}

void WallFollow::Interrupted()
{
}
