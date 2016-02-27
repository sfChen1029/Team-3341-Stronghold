#include "UltraSoundTester.h"
#include "../RobotMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

UltraSoundTester::UltraSoundTester() :
        Subsystem("UltraSoundTester")
{
    for (int i = 0; i < 3; i++)
    {
        sensors[i] = new Ultrasonic(LEFT_TRIGGER_OUTPUT_PIN + i * 2, LEFT_ECHO_INPUT_PIN + i * 2);
        sensors[i]->SetAutomaticMode(true); // turns on automatic mode
        sensors[i]->SetEnabled(true);
    }
}

void UltraSoundTester::InitDefaultCommand()
{

}

void UltraSoundTester::ReadLeftUltra()
{
    std::string sensorNames[3] = {"left", "right", "front"};
    for(int i = 0; i < 3; i++)
    {
        double range = sensors[i]->GetRangeInches();
        std::cout << sensorNames[i] << " sensor (inches): " << range << std::endl;
    }
}

