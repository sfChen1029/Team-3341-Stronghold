#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/Drive.h"
#include "Subsystems/GyroSubsystem.h"
#include "Subsystems/Acquirer.h"
#include "Subsystems/UltraSoundTester.h"
#include "OI.h"
#include "Subsystems/Acquirer.h"
#include "Subsystems/Arm.h"
#include "WPILib.h"

class CommandBase: public Command
{
    public:
        CommandBase(char const* name);
        CommandBase();
        static void init();
        static Drive* drive;
        static OI* oi;
        static GyroSubsystem* gyro;
        static UltraSoundTester* ultraSonic;
        static Acquirer* acquirer;
        static Arm* arm;
};

#endif
