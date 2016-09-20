#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../RobotMap.h"
#include "UltrasonicSensors.h"

UltrasonicSensors::UltrasonicSensors()
{
    for (int i = 0; i < 3; i++)
    {
        sensors[i] = new Ultrasonic(FRONT_TRIGGER_OUTPUT_PIN + i * 2, FRONT_ECHO_INPUT_PIN + i * 2);
        sensors[i]->SetAutomaticMode(true); // turns on automatic mode
        sensors[i]->SetEnabled(true);
    }
}

void UltrasonicSensors::PrintUltraValues()
{
    std::string sensorNames[3] = {"front", "right", "left"};
    for(int i = 0; i < 3; i++)
    {
        double range = sensors[i]->GetRangeInches();
        std::cout << sensorNames[i] << " sensor (inches): " << range << std::endl;
        SmartDashboard::PutNumber("Ultrasonic " + sensorNames[i], range);
    }
}

double  UltrasonicSensors::ReadUltra(uint16_t sensorIndex)
{
	return sensors[sensorIndex]-> GetRangeInches();
}
