#include "ShootBall.h"
#include "CommandBase.h"

ShootBall::ShootBall()
{
    Requires(acquirer);
}

void ShootBall::Initialize()
{
    SetTimeout(2);
    acquirer->Enable();
}

void ShootBall::Execute()
{
    acquirer->BallOut();
}

bool ShootBall::IsFinished()
{
    //return IsTimedOut();
    return !acquirer->IsEnabled();
}

void ShootBall::End()
{
    acquirer->Stop();
    acquirer->Disable();
}

void ShootBall::Interrupted()
{
}
