#include "UltraSonics.h"
#include "../RobotMap.h"
#include <iostream>
#include <fstream>

UltraSonics::UltraSonics() :

    Subsystem("UltraSonics")
{
    using namespace std;
    sensors [0] = new Ultrasonic(LEFT_OUPUT_PIN, LEFT_INPUT_PIN);
    sensors [1] = new Ultrasonic(RIGHT_OUTPUT_PIN, RIGHT_INPUT_PIN);
    sensors [2] = new Ultrasonic(FRONT_OUTPUT_PIN, FRONT_INPUT_PIN);
}

void UltraSonics::InitDefaultCommand()
{
}

double UltraSonics::ReadLeftUltra()
{
    double range = sensors[0]->GetRangeInches();
    std::cout << "left sensor (inches):  " << range << std::endl;
    return range;
}

