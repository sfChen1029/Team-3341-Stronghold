#include "SetDirectionForward.h"

SetDirectionForward::SetDirectionForward()
{
    Requires(drive);
}

void SetDirectionForward::Initialize()
{
    drive->setMult(1.0);
}

void SetDirectionForward::Execute()
{
}

bool SetDirectionForward::IsFinished()
{
    return true;
}

void SetDirectionForward::End()
{
}

void SetDirectionForward::Interrupted()
{
}
