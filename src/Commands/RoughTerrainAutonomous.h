#ifndef RoughTerrainAutonomous_H
#define RoughTerrainAutonomous_H

#include "../CommandBase.h"
#include "Commands/TurnAndDrive.h"
#include "WPILib.h"

class RoughTerrainAutonomous: public CommandBase
{
public:
	RoughTerrainAutonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
       // consts for different sections of autonomous mode
       enum breachModes {BREACHINGROUGH_TERRAIN = 0, AUTONOMOUSDONE};
       bool up, upndown;
       double xinit, yinit, zinit;
       int zf, zi;
       int mode;
       TurnAndDrive* driveDistance;

       void breachRoughTerrain();
       void followWall();
};


#endif
