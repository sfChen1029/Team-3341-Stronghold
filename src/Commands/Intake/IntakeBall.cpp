#include "IntakeBall.h"
#include "CommandBase.h"

IntakeBall::IntakeBall(bool _isEmergency)
{
    isEmergency = _isEmergency;
    Requires(intake);
}

void IntakeBall::Initialize()
{
	if(!intake->DetectBall() || isEmergency)
        intake->Enable();
}

void IntakeBall::Execute()
{
    intake->BallIn();

    if(intake->DetectBall() && !isEmergency)
    	intake->Disable();
}

bool IntakeBall::IsFinished()
{
	return !intake->IsEnabled();
}

void IntakeBall::End()
{
	intake->Stop();
	intake->Disable();
}

void IntakeBall::Interrupted()
{
}
