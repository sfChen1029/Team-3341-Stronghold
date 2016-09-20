#include <Subsystems/Intake.h>
#include "../RobotMap.h"

Intake::Intake(): Subsystem("Intake")
{
    motor = new Talon(ACQUIRER);
    enabled = false;
    ir = new AnalogInput(ACQUIRER_IR);

    THRESHOLD = 2500;
}

void Intake::Enable()
{
    enabled = true;
}

void Intake::Disable()
{
    enabled = false;
}

void Intake::BallOut()
{
    if(enabled)
        motor->SetSpeed(-1);
}

void Intake::BallIn()
{
    if(enabled)
        motor->SetSpeed(0.6);
}

void Intake::Stop()
{
    motor->SetSpeed(0);
}

bool Intake::IsEnabled()
{
    return enabled;
}

bool Intake::DetectBall()
{
    if(GetInput() > THRESHOLD)
        return false;
    else return true;
}

double Intake::GetInput()
{
    return ir->GetValue();
}

