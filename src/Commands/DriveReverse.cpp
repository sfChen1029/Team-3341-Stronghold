#include "DriveReverse.h"

DriveReverse::DriveReverse()
{
    Requires(drive);
}

void DriveReverse::Initialize()
{
    drive->setMult(-1.0);
}

void DriveReverse::Execute()
{
}

bool DriveReverse::IsFinished()
{
    return true;
}

void DriveReverse::End()
{
}

void DriveReverse::Interrupted()
{
}
