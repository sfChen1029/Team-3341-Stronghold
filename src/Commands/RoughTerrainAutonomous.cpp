#include <Commands/LowBarAutonomous.h>
#include "Commands/TurnAndDrive.h"

RoughTerrainAutonomous::RoughTerrainAutonomous() :

  zf(0), zi(0), xinit(0), yinit(0), zinit(0),
  driveDistance(new TurnAndDrive(6.0, 0.0))
{
  mode = breachModes::BREACHINGROUGH_TERRAIN;
  Requires(drive);
 // up = false;
 // upndown = false;
}


// Called just before this Command runs the first time
void RoughTerrainAutonomous::Initialize()
{
	drive->ResetEncoders();
	drive->getAccelerations(&xinit, &yinit, &zinit);
}

// Called repeatedly when this Command is scheduled to run
void RoughTerrainAutonomous::Execute()
{
	switch(mode)
	    {
	        case breachModes::BREACHINGROUGH_TERRAIN:
	            breachRoughTerrain();
	            break;
	          /**
	           //this code is only used for low bar
	            case breachModes::WALLFOLLOWING:
	            followWall();
	            break;
	            */
	    }
}

void RoughTerrainAutonomous::breachRoughTerrain()
{
    drive->getAccelerations(&xinit, &yinit, &zinit);
    drive->arcadeDrive(0.15, 0);
    if (zinit > 1.5 || zinit < 0.5)
    {
        int i = zf;
        zi = i;
        if (up)
            upndown = true;
    }
    if (!up)
    {
        if (zf - zi >= 50)
            up = true;
    }
    std::cout << xinit << " " << yinit << " " << zinit << std::endl;
    zf++;

    // Finished breaching low bar, now follow the wall
    if(upndown || zf > 2000000)
    {
        drive->ResetEncoders();
        // TODO: switch AUTONOMOUSDONE to WALLFOLLOW once BREACHLOWBAR works
        mode = breachModes::AUTONOMOUSDONE;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool RoughTerrainAutonomous::IsFinished()
{
	return mode == breachModes::AUTONOMOUSDONE;
}

// Called once after isFinished returns true
void RoughTerrainAutonomous::End()
{
	 std::cout << "Done!" << std::endl;
	 drive->arcadeDrive(0, 0);
}
