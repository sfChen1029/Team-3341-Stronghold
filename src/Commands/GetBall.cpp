#include "GetBall.h"
#include "CommandBase.h"

GetBall::GetBall()
{
    Requires(acquirer);
}

void GetBall::Initialize()
{
//	if(!acquirer->DetectBall())
	acquirer->Enable();
}

void GetBall::Execute()
{
    acquirer->BallIn();
//
//    if(acquirer->DetectBall())
//    	acquirer->Disable();
}

bool GetBall::IsFinished()
{
	// return this->IsTimedOut();
	return !acquirer->IsEnabled();
}

void GetBall::End()
{
	acquirer->Stop();
	acquirer->Disable();
}

void GetBall::Interrupted()
{
}
