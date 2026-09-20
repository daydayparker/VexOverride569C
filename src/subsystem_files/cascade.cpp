#include "main.h"

void cascadeLoop(void*){
    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
            {
                cascadeState = 0;
            }
            else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
                cascadeState = 1;

            }
            else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
            {
                macroRunning = true;
                cascadeState = 2;
            }
            else{
                cascadeState = 3;
            }
            
            switch (cascadeState)
            {
            //UP: HOLD
            case 0:
                cascadeMotorGroup.move(MAX_VOLTAGE);
                break;
            //DOWN: HOLD
            case 1:
                cascadeMotorGroup.move(-MAX_VOLTAGE);
                break;
            //SCORING MACROS
            case 2:
                cascadeMotorGroup.move(-MAX_VOLTAGE);
                pros::delay(SCORING_MACRO_DURATION / 2);
                cascadeMotorGroup.move(MAX_VOLTAGE);
                pros::delay(SCORING_MACRO_DURATION / 2);
                cascadeState = 3;
                cascadeMotorGroup.move(0);
                macroRunning = false;
            //STOP CASCADE
            case 3:
                cascadeMotorGroup.move(0);
                break;
            default:
                cascadeMotorGroup.move(0); 
                break;  
            }
        }

        pros::delay(LOOP_DURATION);
    } 
}