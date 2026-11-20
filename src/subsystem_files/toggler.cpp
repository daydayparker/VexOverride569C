#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/states.hpp"

void togglerLoop(void*){
    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
            {
                togglerState = 0;
            }
            else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
                togglerState = 1;
            }
            else{
                togglerState = 2;
            }
            
            switch (togglerState)
            {
            //SPIN FORWARDS: HOLD
            case 0:
                togglerMotor.move(MAX_VOLTAGE);
                break;
            //SPIN BACKWARDS: HOLD
            case 1:
                togglerMotor.move(-MAX_VOLTAGE);
                break;
            //STOP TOGGLER
            case 2:
                togglerMotor.move(0);
                break;
            default:
                togglerMotor.move(0); 
                break;  
            }
        }

        pros::delay(LOOP_DURATION);
    }

}