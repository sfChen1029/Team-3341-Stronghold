#ifndef BreachDefense_H
#define BreachDefense_H

#include "../CommandBase.h"
#include "WPILib.h"
//#include "GyroSubsystem.h"

class LowBar: public CommandBase
{
public:
	LowBar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	//BuiltInAccelerometer* acc;
	bool up, upndown;
	double xinit, yinit, zinit;
	int zf,zi;
};

#endif
