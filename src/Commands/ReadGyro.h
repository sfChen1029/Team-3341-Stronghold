#ifndef ReadGyro_H
#define ReadGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReadGyro: public CommandBase
{
public:
	ReadGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
