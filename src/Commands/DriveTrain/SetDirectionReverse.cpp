#include "SetDirectionReverse.h"

SetDirectionReverse::SetDirectionReverse()
{
    Requires(drive);
}

void SetDirectionReverse::Initialize()
{
    drive->setMult(-1.0);
}

void SetDirectionReverse::Execute()
{
}

bool SetDirectionReverse::IsFinished()
{
    return true;
}

void SetDirectionReverse::End()
{
}

void SetDirectionReverse::Interrupted()
{
}
