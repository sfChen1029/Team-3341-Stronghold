#include "MoveArm.h"
#include "../../OI.h"

MoveArm::MoveArm()
{
    Requires(arm);
}

void MoveArm::Initialize()
{
    arm->ArmOn();
}

void MoveArm::Execute()
{
    double control;
    if(fabs(oi->getOperatorStick()->GetY()) >= 0.05)
    {
        double x = oi->getOperatorStick()->GetY();
        double a = 0.7;
        double b = 0;

        if(x > 0)
            control = b + (1 - b) * ((a * pow(x, 3) + (1 - a) * x));
        else
            control = -b + (1 - b) * ((a * pow(x, 3) + (1 - a) * x));
    }
    else
    {
        control = 0;
    }

    SmartDashboard::PutNumber("Arm motor value", control);
    arm->moveArm((float)control);

}

bool MoveArm::IsFinished()
{
    return false;
}

void MoveArm::End()
{
    arm->ArmOff();
}

void MoveArm::Interrupted()
{
}
