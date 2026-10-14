#include "main.h"

void macrosLoop(void*){
    while (true){
        if (!macroRunning)
        {
            if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
                macroRunning = true;
                macroState = 1;
            }
            else{
                macroState = 0;
            }

            switch (macroState)
            {
            case 0:
                break;
            case 1:
                cascadeState = 1;
                cascadeMotorGroup.move(-MAX_VOLTAGE);
                pros::delay(SCORING_MACRO_DURATION / 2.0);

                cascadeState = 0;
                cascadeMotorGroup.move(MAX_VOLTAGE);
                intakeState = 0;
                intakeMotorGroup.move(-MAX_VOLTAGE);
                pros::delay(SCORING_MACRO_DURATION / 8.0);

                anglerState = 1;
                anglerMotor.move(-MAX_VOLTAGE);
                pros::delay(SCORING_MACRO_DURATION * (3.0 / 8.0));
                
                anglerState = 2;
                anglerMotor.move(0);
                cascadeState = 2;
                cascadeMotorGroup.move(0);
                intakeState = 1;
                intakeMotorGroup.move(0);
                macroRunning = false;
                break;
            default:
                break;
            }
        }

        pros::delay(LOOP_DURATION);
    }
}

