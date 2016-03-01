#ifndef WallFollow_H
#define WallFollow_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "NewPIDController.h"

class WallFollow: public CommandBase
{
    private:
        NewPIDController* wallDistPID;
        NewPIDController* distTravelledPID;

        // Distances in feet
        double DISTANCE_FROM_WALL;
        double DISTANCE_TO_TARGET;
    public:
        WallFollow(double distanceFromWall, double distanceToTarget);
        void Initialize();
        void Execute();bool IsFinished();
        void End();
        void Interrupted();
};

#endif
