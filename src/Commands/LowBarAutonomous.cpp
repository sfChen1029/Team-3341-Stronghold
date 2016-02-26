#include <Commands/LowBar.h>

LowBar::LowBar()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive);
	//Requires(gyro);
	//acc = new BuiltInAccelerometer();
	up = false;
	upndown = false;
}

// Called just before this Command runs the first time
void LowBar::Initialize()
{
	//drive->ResetEncoders();
	//drive->getAccel()->
	std::cout<<"iiiiiiiinnnnnnnniiiiiiitttttt"<<std::endl;
	drive->getAccelerations(&xinit,&yinit,&zinit);
		zf = 0;//acc->GetZ();
		zi = 0;
}

// Called repeatedly when this Command is scheduled to run
void LowBar::Execute()
{
	drive->getAccelerations(&xinit,&yinit,&zinit);
	drive->arcadeDrive(0.35, 0);
	if(zinit>1.5 || zinit<0.5)
	{
		int i = zf;
		zi = i;
		if(up)
			upndown = true;
	}
	if(!up)
	{
		if(zf-zi>=50)
			up = true;
	}
	std::cout<<xinit<<" "<<yinit<<" "<<zinit<<std::endl;
	zf++;
}

// Make this return true when this Command no longer needs to run execute()
bool LowBar::IsFinished()
{
	return upndown || zf>2000000;
}

// Called once after isFinished returns true
void LowBar::End()
{
	//delete acc;
	std::cout<<"Done!"<<std::endl;
	drive->arcadeDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowBar::Interrupted()
{

}
