#ifndef MoatRun_H
#define MoatRun_H

#include "../../CommandBase.h"
#include "WPILib.h"
#include "../DriveTrain/TurnAndDrive.h"

class MoatRun: public CommandBase
{
    private:
        TurnAndDrive* drive;
public:
	MoatRun();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
