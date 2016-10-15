#ifndef EjectBall_H
#define EjectBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class EjectBall: public CommandBase
{
public:
	EjectBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
