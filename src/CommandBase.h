#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>

#include "WPILib.h"
#include "OI.h"

#include "Commands/Command.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Arm.h"

class CommandBase: public Command
{
    public:
        CommandBase(char const* name);
        CommandBase();
        static void init();
        static DriveTrain* drive;
        static OI* oi;
        static Intake* intake;
        static Arm* arm;
};

#endif
