#include <math.h>

#include "../RobotMap.h"
#include "../CommandBase.h"

#include "DriveTrain.h"

#include "Commands/ArcadeDriveTrain.h"

#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() :
    Subsystem("DriveTrain"), left(new Talon(DRIVE_LEFT)), right(new Talon(DRIVE_RIGHT)),
    encoderLeft(new Encoder(ENCODER_LEFT_1, ENCODER_LEFT_2)),
    encoderRight(new Encoder(ENCODER_RIGHT_1, ENCODER_RIGHT_2)), mult(1.0),
	ticksToDistance(114), // 112 < ticksToDistance < 117
	accel(), gyro(new AnalogGyro(GYROPIN))
{
    encoderLeft->SetDistancePerPulse(1.0);
    encoderRight->SetDistancePerPulse(1.0);

    gyro->Calibrate();
    gyro->Reset();
}


DriveTrain::~DriveTrain()
{
    delete left;
    delete right;    
    delete encoderLeft;
    delete encoderRight;
    delete accel;
    delete gyro;
}

void DriveTrain::setMult(float m)
{
    mult = m;
}

int DriveTrain::getMult()
{
	return mult;
}

void DriveTrain::ResetEncoders()
{
    encoderLeft->Reset();
    encoderRight->Reset();
}

void DriveTrain::arcadeDrive(float moveValue, float rotateValue)
{
    float leftMotorOutput;
    float rightMotorOutput;

    moveValue = DriveTrain::Limit(moveValue, 1.0) * mult;
    rotateValue = -DriveTrain::Limit(rotateValue, 1.0);

    // Standard ArcadeDriveTrain algorithm from Google
    if(moveValue > 0.0)
    {
        if(rotateValue > 0.0)
        {
            leftMotorOutput = moveValue - rotateValue;
            rightMotorOutput = max(moveValue, rotateValue);
        }
        else
        {
            leftMotorOutput = max(moveValue, -rotateValue);
            rightMotorOutput = moveValue + rotateValue;
        }
    }
    else
    {
        if(rotateValue > 0.0)
        {
            leftMotorOutput = - max(-moveValue, rotateValue);
            rightMotorOutput = moveValue + rotateValue;
        }
        else
        {
            leftMotorOutput = moveValue - rotateValue;
            rightMotorOutput = - max(-moveValue, -rotateValue);
        }
    }

    float limitedL = DriveTrain::Limit(leftMotorOutput, 1.0);
    float limitedR = -DriveTrain::Limit(rightMotorOutput, 1.0);

    left->Set(-limitedL);
    right->Set(-limitedR);
}

float DriveTrain::Limit(float num, float max)
{
    if(num > max)
        return max;

    if(num < -max)
        return -max;

    return num;
}

// Return distance in feet
double DriveTrain::getDistance()
{
    // Average of both encoders (must negate to get proper direction)
    return 
    (
        (double) ((encoderLeft->get()) / ticksToDistance) -
        (double) ((encoderRight->get()) / ticksToDistance)
    ) / -2.0;
}

double DriveTrain::getRate()
{
    // Average of both encoder rates (must negate to get proper direction)
    // TODO: test to see if negation is necessary
    return 
    (
        (double) ((encoderLeft->getRate()) / ticksToDistance) -
        (double) ((encoderRight->getRate()) / ticksToDistance)
    ) / -2.0;
                 
}

void DriveTrain::getAccelerations(double* x, double* y, double* z)
{
	*x = accel->getX();
	*y = accel->getY();
	*z = accel->getZ();
}

void DriveTrain::InitDefaultCommand()
{
    SetDefaultCommand(new ArcadeDriveTrain());
}

double DriveTrain::getLeftEncoderDistance()
{
	return this->encoderLeft->getDistance();
}

double DriveTrain::getRightEncoderDistance()
{
	return -this->encoderRight->getDistance();
}

double DriveTrain::getGyroAngle()
{
    return -gyro->GetAngle();
}

void DriveTrain::ResetGyro()
{
    gyro->Reset();
}
