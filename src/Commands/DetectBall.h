#ifndef DetectBall_H
#define DetectBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class DetectBall: public CommandBase
{
public:
	DetectBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
