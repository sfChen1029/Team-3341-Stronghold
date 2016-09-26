#ifndef LiftDoor_H
#define LiftDoor_H

#include "../../CommandBase.h"
#include "WPILib.h"

class LiftDoor: public CommandBase
{
public:
	float const static DOOR_ANGLE; //the angle at which arm needs to be to lift door
	LiftDoor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
