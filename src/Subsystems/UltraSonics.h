#ifndef UltraSonics_H
#define UltraSonics_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class UltraSonics: public Subsystem
{
    private:
        const uint16_t LEFTSENSOR = 0;
        const uint16_t RIGHTSENSOR = 1;
        const uint16_t FRONTSENSOR = 2;
        const uint16_t MAX_ULTRASONIC = 3;
        const uint32_t LEFT_INPUT_PIN = 4;
        const uint32_t LEFT_OUPUT_PIN = 5;
        const uint32_t RIGHT_INPUT_PIN = 6;
        const uint32_t RIGHT_OUTPUT_PIN = 7;
        const uint32_t FRONT_INPUT_PIN = 8;
        const uint32_t FRONT_OUTPUT_PIN = 9;
        Ultrasonic* sensors[3];

    public:
        UltraSonics();
        void InitDefaultCommand();
        double ReadLeftUltra();
};

#endif
