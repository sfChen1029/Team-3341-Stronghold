#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/LowBarAutonomous.h"
#include "Commands/MoveArm.h"
#include "Commands/AutonomousProgram.h"
#include "Commands/TurnAndDrive.h"
#include "Commands/WallFollow.h"
#include "CommandBase.h"
#include <stdint.h>
#include <Subsystems/Acquirer.h>

class Robot: public IterativeRobot
{
    private:
        // Autonomous testing commands
        LowBarAutonomous* autonomousCommand;
        TurnAndDrive* driveCommand;
        WallFollow* wallFollowCommand;

        LiveWindow* lw;

        void RobotInit()
        {
            CommandBase::init();

            autonomousCommand = new LowBarAutonomous();

            // Try to maintain the distance from the wal constant
            double distanceFromWall = CommandBase::ultraSonic->ReadUltra(
                    CommandBase::ultraSonic->LEFTSENSOR);
            wallFollowCommand = new WallFollow(distanceFromWall, 6.0,
                    CommandBase::ultraSonic->LEFTSENSOR);

            // Distance SetPoint: 3 Feet
            driveCommand = new TurnAndDrive(3.0, 0.0);

            lw = LiveWindow::GetInstance();
            //the camera name (ex "cam0") can be found through the roborio web interface
            CameraServer::GetInstance()->StartAutomaticCapture("cam0");
            CameraServer::GetInstance()->SetQuality(1500);
            std::shared_ptr<USBCamera> usbCamptr =
                    CameraServer::GetInstance()->m_camera; //(new USBCamera("cam1",true));
            if (usbCamptr != nullptr)
            {
                usbCamptr->SetBrightness(2);
                usbCamptr->SetExposureAuto();
            }
        }

        void DisabledPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void AutonomousInit()
        {
            if (autonomousCommand != NULL)
                autonomousCommand->Start();
        }

        void AutonomousPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void TeleopInit()
        {
            if (autonomousCommand != NULL)
                autonomousCommand->Cancel();
            CommandBase::drive->ResetEncoders();
            CommandBase::gyro->ResetGyro();
            // arm->Start();
        }

        void TeleopPeriodic()
        {
            SmartDashboard::PutNumber("IR Analog Input",
                    CommandBase::acquirer->GetInput());
            SmartDashboard::PutBoolean("Ball Loaded",
                    CommandBase::acquirer->DetectBall());
            SmartDashboard::PutNumber("Right Encoder distance",
                    CommandBase::drive->GetRightEncoderDistance());
            SmartDashboard::PutNumber("Left Encoder distance",
                    CommandBase::drive->GetLeftEncoderDistance());
            SmartDashboard::PutNumber("Driver Slider Value",
                    CommandBase::oi->getDriveStick()->GetThrottle());
            CommandBase::ultraSonic->PrintUltraValues();
            Scheduler::GetInstance()->Run();
        }

        void TestPeriodic()
        {
            lw->Run();
        }
};

START_ROBOT_CLASS(Robot);
