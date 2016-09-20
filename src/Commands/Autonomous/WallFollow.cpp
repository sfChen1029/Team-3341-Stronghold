#include "WallFollow.h"
#include "ArcadeDrive.h"

// distanceToWall in inches, distanceToTarget in feet
WallFollow::WallFollow(double distanceFromWall, double distanceToTarget, int sensorToUse) :
    DISTANCE_FROM_WALL(distanceFromWall), DISTANCE_TO_TARGET(distanceToTarget), SENSORINUSE(sensorToUse)
{
    Requires(ultraSonic);
    Requires(drive);

    wallDistPID = new WVPIDController(0.01, 0, 0, distanceFromWall, false);
    distTravelledPID = new WVPIDController(0.07, 0, 0, distanceToTarget, false);
}

void WallFollow::Initialize()
{
    drive->ResetEncoders();
}

void WallFollow::Execute()
{
    double distTravelledPV = drive->GetDistance();
    double distFromWallPV = ultraSonic->ReadUltra(SENSORINUSE);

    //std::cout << "Distance Travelled: " << distTravelledPV;
    //std::cout << "Distance From Wall: " << distFromWallPV;

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
