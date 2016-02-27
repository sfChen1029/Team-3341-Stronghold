#include "UltraSoundTester.h"
#include "../RobotMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

UltraSoundTester::UltraSoundTester() :
		Subsystem("ExampleSubsystem")
{
	        using namespace std;
		    sensors[0] = new Ultrasonic(LEFT_TRIGGER_OUPUT_PIN, LEFT_ECHO_INPUT_PIN);
			sensors[0]->SetAutomaticMode(true); // turns on automatic mode
			sensors[0]->SetEnabled(true);

			sensors[1] = new Ultrasonic(RIGHT_TRIGGER_OUPUT_PIN, RIGHT_ECHO_INPUT_PIN);
			sensors[1]->SetAutomaticMode(true); // turns on automatic mode
			sensors[1]->SetEnabled(true);

			sensors[2] = new Ultrasonic(FRONT_TRIGGER_OUPUT_PIN, FRONT_ECHO_INPUT_PIN);
			sensors[2]->SetAutomaticMode(true); // turns on automatic mode
			sensors[2]->SetEnabled(true);

		  // sensors [1] = new Ultrasonic(RIGHT_OUTPUT_PIN, RIGHT_INPUT_PIN);
		  // sensors [2] = new Ultrasonic(FRONT_OUTPUT_PIN, FRONT_INPUT_PIN);
}

void UltraSoundTester::InitDefaultCommand()
{

}

void UltraSoundTester::PrintUltraValues()
{
    double range = sensors[0]-> GetRangeInches();
    	std::cout << "left sensor (inches):  " << range  << std::endl;
    double range1 = sensors[1]-> GetRangeInches();
        std::cout << "right sensor (inches):  " << range1  << std::endl;
    double range2 = sensors[2] -> GetRangeInches();
    	std::cout << "right sensor (inches):  " << range2  << std::endl;

    	SmartDashboard::PutNumber("Ultrasonic 1", range);
    	SmartDashboard::PutNumber("Ultrasonic 2", range1);
    	SmartDashboard::PutNumber("Ultrasonic 3", range2);
}

double  UltraSoundTester::ReadLeftUltra()
{
	//sensors[0]->Ping();
    double range = sensors[0]-> GetRangeInches();

    	return range;
}

double UltraSoundTester::ReadRightUltra()
{
	double value = sensors[1]-> GetRangeInches();
	return value;
}

double UltraSoundTester::ReadFrontUltra()
{
	double value = sensors[2] -> GetRangeInches();
	return value;
}

