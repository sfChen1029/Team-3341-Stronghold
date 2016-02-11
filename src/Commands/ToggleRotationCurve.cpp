#include "ToggleRotationCurve.h"

ToggleRotationCurve::ToggleRotationCurve()
{
    Requires(drive);
}

void ToggleRotationCurve::Initialize()
{
    drive->toggleRotationCurve();
}

void ToggleRotationCurve::Execute()
{
}

bool ToggleRotationCurve::IsFinished()
{
    return true;
}

void ToggleRotationCurve::End()
{
}

void ToggleRotationCurve::Interrupted()
{
}
