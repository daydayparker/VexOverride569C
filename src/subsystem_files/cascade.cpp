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
            else{
                cascadeState = 2;
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
            //STOP CASCADE
            case 2:
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