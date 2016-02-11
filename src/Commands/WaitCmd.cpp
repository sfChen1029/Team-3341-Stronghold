#include <Commands/WaitCmd.h>

WaitCmd::WaitCmd(double seconds)
{
    SetTimeout(seconds);
}

void WaitCmd::Initialize()
{
}

void WaitCmd::Execute()
{
}

bool WaitCmd::IsFinished()
{
    return IsTimedOut();
}

void WaitCmd::End()
{
}

void WaitCmd::Interrupted()
{
}
