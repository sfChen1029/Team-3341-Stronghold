#include "GetBall.h"
#include "CommandBase.h"

GetBall::GetBall(bool _isEmergency)
{
    isEmergency = _isEmergency;
    Requires(acquirer);
}

void GetBall::Initialize()
{
	if(!acquirer->DetectBall() || isEmergency)
        acquirer->Enable();
}

void GetBall::Execute()
{
    acquirer->BallIn();

    if(acquirer->DetectBall() && !isEmergency)
    	acquirer->Disable();
}

bool GetBall::IsFinished()
{
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
