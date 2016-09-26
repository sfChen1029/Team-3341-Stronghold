#include <CameraServer.h>
#include <Commands/Autonomous/LowBarAutonomous.h>
#include <Commands/Autonomous/MoatRun.h>
#include <Commands/Autonomous/WallFollow.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <RobotBase.h>
#include <stddef.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Subsystems/DriveTrain.h>
#include <USBCamera.h>
#include <iostream>
#include <memory>

class Robot: public IterativeRobot
{
    private:
        // Autonomous testing commands
        LowBarAutonomous* autonomousCommand;
        Command* driveCommand;
        WallFollow* wallFollowCommand;

        LiveWindow* lw;

        void RobotInit()
        {
            CommandBase::init();

           // autonomousCommand = new LowBarAutonomous();

            // Try to maintain the distance from the wal constant
            double distanceFromWall = CommandBase::drive->readUltra(
                    UltrasonicSensors::LEFTSENSOR);
            wallFollowCommand = new WallFollow(distanceFromWall, 6.0,
                    UltrasonicSensors::LEFTSENSOR);

            // use this to breach defense
            // driveCommand = new TurnAndDrive(20.0, 0.0);

            // Use this to only reach defense
            //driveCommand = new TurnAndDrive(6.0,0.0);

            // Use this for moat
            driveCommand = new MoatRun();

            lw = LiveWindow::GetInstance();
            //the camera name (ex "cam0") can be found through the roborio web interface
            CameraServer::GetInstance()->StartAutomaticCapture("cam1");
            CameraServer::GetInstance()->SetQuality(1500);
            //std::shared_ptr<USBCamera> usbCamptr = CameraServer::GetInstance()->m_camera; //(new USBCamera("cam1",true));
            //if (usbCamptr != nullptr)
            //{
            //    usbCamptr->SetBrightness(2);
            //    usbCamptr->SetExposureAuto();
            //}
        }

        void DisabledPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void AutonomousInit()
        {
            if (driveCommand != NULL)
                driveCommand->Start();
        }

        void AutonomousPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void TeleopInit()
        {
            if (autonomousCommand != NULL)
                autonomousCommand->Cancel();
            CommandBase::drive->resetEncoders();
            CommandBase::drive->resetGyro();
        }

        void TeleopPeriodic()
        {
            SmartDashboard::PutNumber("Gyro Angle",
                    CommandBase::drive->getGyroAngle());
            SmartDashboard::PutNumber("IR Analog Input",
                    CommandBase::intake->getInput());
            std::cout << "IR Analog Input: " << CommandBase::intake->getInput() << std::endl;
            SmartDashboard::PutBoolean("Ball Loaded",
                    CommandBase::intake->DetectBall());
            //SmartDashboard::PutNumber("Right Encoder distance",
            //        CommandBase::drive->GetRightEncoderDistance());
            //SmartDashboard::PutNumber("Left Encoder distance",
            //        CommandBase::drive->GetLeftEncoderDistance());
            //SmartDashboard::PutNumber("Driver Slider Value",
            //        CommandBase::oi->getDriveStick()->GetThrottle());
            //CommandBase::ultraSonic->PrintUltraValues();
            Scheduler::GetInstance()->Run();
        }

        void TestPeriodic()
        {
            lw->Run();
        }
};

START_ROBOT_CLASS(Robot);
