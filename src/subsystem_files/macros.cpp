#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/macros.hpp"
#include "subsystem_headers/states.hpp"

void macrosLoop(void*){
    while (true){
        if (!macroRunning)
        {
            if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
                //macroRunning = true;
                //macroState = 1;
            }
            else{
                //macroState = 0;
            }

            switch (macroState)
            {
            case 0:
                break;
            case 1:
                break;
            default:
                break;
            }
        }

        pros::delay(LOOP_DURATION);
    }
}

