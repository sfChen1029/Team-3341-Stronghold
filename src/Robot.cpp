#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/MoveArm.h"
#include "Commands/AutonomousProgram.h"
#include "CommandBase.h"
#include <stdint.h>
#include <Subsystems/Acquirer.h>

class Robot: public IterativeRobot
{
    private:
        AutonomousProgram* autonomousCommand;
        LiveWindow* lw;
        Command* arm;

        void RobotInit()
        {
            CommandBase::init();
            autonomousCommand = new AutonomousProgram();
            lw = LiveWindow::GetInstance();
            arm = new MoveArm();
        }

        void DisabledPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void AutonomousInit()
        {
            if(autonomousCommand != NULL)
                autonomousCommand->Start();
        }

        void AutonomousPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void TeleopInit()
        {
            if(autonomousCommand != NULL)
                autonomousCommand->Cancel();
            CommandBase::drive->ResetEncoders();
            CommandBase::gyro->ResetGyro();
            arm->Start();
        }

        void TeleopPeriodic()
        {
            SmartDashboard::PutNumber("IR Analog Input", CommandBase::acquirer->GetInput());
            SmartDashboard::PutBoolean("Ball Loaded", CommandBase::acquirer->DetectBall());

            Scheduler::GetInstance()->Run();
        }

        void TestPeriodic()
        {
            lw->Run();
        }
};

START_ROBOT_CLASS(Robot);
