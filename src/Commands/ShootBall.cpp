#include "ShootBall.h"
#include "CommandBase.h"

ShootBall::ShootBall()
{
    Requires(acquirer);
}

void ShootBall::Initialize()
{
    acquirer->Enable();
}

void ShootBall::Execute()
{
    acquirer->BallOut();
}

bool ShootBall::IsFinished()
{
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
