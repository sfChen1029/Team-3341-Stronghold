#ifndef WallFollow_H
#define WallFollow_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "NewPIDController.h"

class WallFollow: public CommandBase
{
private:
	NewPIDController* pid;
	double DISTANCE_FROM_WALL;
	double DISTANCE_TO_TARGET;
	double DRIVE_SPEED;
public:
	WallFollow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
