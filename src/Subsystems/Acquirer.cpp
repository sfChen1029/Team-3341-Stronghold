#include <Subsystems/Acquirer.h>
#include "../RobotMap.h"

Acquirer::Acquirer(): Subsystem("Acquirer")
{
    motor = new Talon(ACQUIRER);
    enabled = false;
    ir = new AnalogInput(ACQUIRER_IR);

    THRESHOLD = 2500;
}

void Acquirer::Enable()
{
    enabled = true;
}

void Acquirer::Disable()
{
    enabled = false;
}

void Acquirer::BallOut()
{
    if(enabled)
        motor->SetSpeed(-1);
}

void Acquirer::BallIn()
{
    if(enabled)
        motor->SetSpeed(0.6);
}

void Acquirer::Stop()
{
    motor->SetSpeed(0);
}

bool Acquirer::IsEnabled()
{
    return enabled;
}

bool Acquirer::DetectBall()
{
    if(GetInput() > THRESHOLD)
        return false;
    else return true;
}

double Acquirer::GetInput()
{
    return ir->GetValue();
}
