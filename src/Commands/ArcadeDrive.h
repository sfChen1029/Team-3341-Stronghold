#ifndef ArcadeDrive_H
#define ArcadeDrive_H

#include "../CommandBase.h"
#include "../NewPIDController.h"
#include "WPILib.h"

class ArcadeDrive: public CommandBase
{
    public:
        ArcadeDrive();
        void Initialize();
        void Execute();
        bool IsFinished();
        void End();
        void Interrupted();

    private:
        bool isReset;
        NewPIDController* anglePid;

        // Map linear output to cubic output (for turning and driving more precisely)
        double mapToCubic(double a, double b, double signal);
};

#endif
