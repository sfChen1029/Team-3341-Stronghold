#include "DriveForward.h"

DriveForward::DriveForward()
{
    Requires(drive);
}

void DriveForward::Initialize()
{
    drive->setMult(1.0);
}

void DriveForward::Execute()
{
}

bool DriveForward::IsFinished()
{
    return true;
}

void DriveForward::End()
{
}

void DriveForward::Interrupted()
{
}
