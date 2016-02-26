#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/MoveArm.h"
#include "Commands/AutonomousProgram.h"
#include "Commands/TurnAndDrive.h"
#include "CommandBase.h"
#include <stdint.h>
#include <Subsystems/Acquirer.h>

class Robot: public IterativeRobot
{
    private:
        AutonomousProgram* autonomousCommand;
        // TESTING ENCODERS with TurnAndDrive, will be removed later
        TurnAndDrive* driveCommand;
        LiveWindow* lw;
        //Command* arm;

        void RobotInit()
        {
            CommandBase::init();
            autonomousCommand = new AutonomousProgram();
            // Distance SetPoint: 3 Feet
            driveCommand = new TurnAndDrive(3.0, 0.0);
            lw = LiveWindow::GetInstance();
           // arm = new MoveArm();
            //CameraServer::GetInstance()->SetQuality(500);
            				////the camera name (ex "cam0") can be found through the roborio web interface
//            			    CameraServer::GetInstance()->StartAutomaticCapture("cam0");
//            			    CameraServer::GetInstance()->SetQuality(1500);
//            			    std::shared_ptr<USBCamera> usbCamptr = CameraServer::GetInstance()->m_camera;//(new USBCamera("cam1",true));
//            			    if(usbCamptr!=nullptr)
//            			    {
//            			    	usbCamptr->SetBrightness(2);
//            			    	usbCamptr->SetExposureAuto();
//            			    }

        }

        void DisabledPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void AutonomousInit()
        {
            if(driveCommand != NULL)
                driveCommand->Start();
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
           // arm->Start();
        }

        void TeleopPeriodic()
        {
            SmartDashboard::PutNumber("IR Analog Input", CommandBase::acquirer->GetInput());
            SmartDashboard::PutBoolean("Ball Loaded", CommandBase::acquirer->DetectBall());
            SmartDashboard::PutNumber("Right Encoder distance", CommandBase::drive->GetRightEncoderDistance());
            SmartDashboard::PutNumber("Left Encoder distance", CommandBase::drive->GetLeftEncoderDistance());
            Scheduler::GetInstance()->Run();
//
//            while (IsOperatorControl() && IsEnabled())
//            		{
//            		Scheduler::GetInstance()->Run();
//            			Wait(0.005);				// wait for a motor update time
//            		}

        }

        void TestPeriodic()
        {
            lw->Run();
        }
};

START_ROBOT_CLASS(Robot);
