#ifndef ShootBall_H
#define ShootBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShootBall: public CommandBase
{
public:
	ShootBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
