#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/states.hpp"

void clawLoop(void*){

    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
            {
                if (clawState == 0) {
                    clawState = 2;
                }
                else {
                    clawState = 0;
                }
            }
            else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
                if (clawState == 1) {
                    clawState = 2;
                }
                else {
                    clawState = 1;
                }
            }
 
            switch (clawState)
            {
            //TAKE IN CUPS AND PINS: TOGGLE
            case 0:
                clawMotor.move(MAX_VOLTAGE);
                break;
            //RELEASE CUPS AND PINS: TOGGLE
            case 1:
                clawMotor.move(-MAX_VOLTAGE);
                break;
            //STOP CLAW MOTOR
            case 2:
                clawMotor.move(0);
                break;
            default:
                clawMotor.move(0); 
                break;  
            }
        }

        pros::delay(LOOP_DURATION);
    } 
}