#include "EjectBall.h"
#include "CommandBase.h"

EjectBall::EjectBall()
{
    Requires(intake);
}

void EjectBall::Initialize()
{
    intake->Enable();
}

void EjectBall::Execute()
{
    intake->BallOut();
}

bool EjectBall::IsFinished()
{
    return !intake->IsEnabled();
}

void EjectBall::End()
{
    intake->Stop();
    intake->Disable();
}

void EjectBall::Interrupted()
{
}
