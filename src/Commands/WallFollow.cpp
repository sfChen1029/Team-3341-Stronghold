#include "WallFollow.h"
#include "ArcadeDrive.h"

// distanceToWall in inches, distanceToTarget in feet
WallFollow::WallFollow(double distanceFromWall, double distanceToTarget) :
    DISTANCE_FROM_WALL(distanceFromWall), DISTANCE_TO_TARGET(distanceToTarget)
{
    Requires(ultraSonic);
    Requires(drive);

    wallDistPID = new NewPIDController(0.01, 0, 0, distanceFromWall, false);
    distTravelledPID = new NewPIDController(0.15, 0, 0, distanceToTarget, false);
}

void WallFollow::Initialize()
{
    drive->ResetEncoders();
}

void WallFollow::Execute()
{
    double distTravelledPV = drive->GetDistance();
    double distFromWallPV = ultraSonic->ReadUltra(UltrasonicSensors::RIGHTSENSOR);

    std::cout << "Distance Travelled: " << distTravelledPV;
    std::cout << "Distance From Wall: " << distFromWallPV;

    double distTravelledOutput = distTravelledPID->Tick(distTravelledPV);
    double distFromWallOutput = wallDistPID->Tick(distFromWallPV);

    drive->arcadeDrive(distTravelledOutput, distFromWallOutput);
}

bool WallFollow::IsFinished()
{
    return fabs(drive->GetDistance() - DISTANCE_TO_TARGET) < 0.1;
}

void WallFollow::End()
{
    delete wallDistPID;
}

void WallFollow::Interrupted()
{
}
