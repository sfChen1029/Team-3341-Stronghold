#ifndef UltraSoundTester_H
#define UltraSoundTester_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class UltraSoundTester: public Subsystem
{
    private:
        const uint16_t LEFTSENSOR = 0;
        const uint16_t RIGHTSENSOR = 1;
        const uint16_t FRONTSENSOR = 2;
        const uint16_t MAX_ULTRASONIC = 3;
        const uint32_t LEFT_ECHO_INPUT_PIN = 4;
        const uint32_t LEFT_TRIGGER_OUTPUT_PIN = 5;
        const uint32_t RIGHT_ECHO_INPUT_PIN = 6;
        const uint32_t RIGHT_TRIGGER_OUTPUT_PIN = 7;
        const uint32_t FRONT_ECHO_INPUT_PIN = 8;
        const uint32_t FRONT_TRIGGER_OUTPUT_PIN = 9;
        Ultrasonic* sensors[3];
    public:
        UltraSoundTester();
        void InitDefaultCommand();
        void
        ReadLeftUltra();
};

#endif

