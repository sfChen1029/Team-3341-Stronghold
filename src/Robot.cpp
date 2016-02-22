#include "WPILib.h"
#include "NetworkTablesInterface.h"
#include "Commands/Command.h"
#include "Commands/AutonomousProgram.h"
#include "CommandBase.h"
#include <stdint.h>

class Robot: public IterativeRobot
{
    private:
        AutonomousProgram* autonomousCommand;
        LiveWindow* lw;

        void RobotInit()
        {
            CommandBase::init();
            autonomousCommand = new AutonomousProgram();
            lw = LiveWindow::GetInstance();
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
            // This makes sure that the autonomous stops running when
            // teleop starts running. If you want the autonomous to
            // continue until interrupted by another command, remove
            // this line or comment it out.
            if(autonomousCommand != NULL)
                autonomousCommand->Cancel();
            CommandBase::drive->ResetEncoders();
            CommandBase::gyro->ResetGyro();
        }

        void TeleopPeriodic()
        {
            //printf("Gyro Angle: %f\n", CommandBase::gyro->GetAngle());
            //CommandBase::ir->printValues();
            //printf("Ticks: %f\n", CommandBase::elevator->getS2Distance());

            Scheduler::GetInstance()->Run();
        }

        void TestPeriodic()
        {
            lw->Run();
        }
};

START_ROBOT_CLASS(Robot);


