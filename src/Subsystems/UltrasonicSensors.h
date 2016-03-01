#ifndef UltraSoundTester_H
#define UltraSoundTester_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class UltrasonicSensors: public Subsystem
{
    private:
        const uint16_t NUM_ULTRASONICS = 3;
        const uint32_t FRONT_ECHO_INPUT_PIN = 4;
		const uint32_t FRONT_TRIGGER_OUTPUT_PIN = 5;
		const uint32_t RIGHT_ECHO_INPUT_PIN = 6;
		const uint32_t RIGHT_TRIGGER_OUTPUT_PIN = 7;
		const uint32_t LEFT_ECHO_INPUT_PIN = 8;
        const uint32_t LEFT_TRIGGER_OUTPUT_PIN = 9;

        Ultrasonic* sensors[3];

    public:
        const static uint16_t FRONTSENSOR = 0;
        const static uint16_t RIGHTSENSOR = 1;
        const static uint16_t LEFTSENSOR = 2;

        UltrasonicSensors();
        void InitDefaultCommand();
        double ReadUltra(uint16_t sensorIndex);
        void PrintUltraValues();
};

#endif
