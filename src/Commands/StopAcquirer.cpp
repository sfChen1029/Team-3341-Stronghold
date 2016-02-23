#include "StopAcquirer.h"
#include "CommandBase.h"

StopAcquirer::StopAcquirer()
{
    Requires(acquirer);
}

void StopAcquirer::Initialize()
{
}

void StopAcquirer::Execute()
{
    acquirer->Stop();
}

bool StopAcquirer::IsFinished()
{
    return true;
}

void StopAcquirer::End()
{
    acquirer->Disable();
}

void StopAcquirer::Interrupted()
{
}
