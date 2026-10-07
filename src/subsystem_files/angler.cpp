#include "main.h"

void anglerLoop(void*){
    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT))
            {
                isAnglerUp = !isAnglerUp;
            }
        
            anglerPneumatic.set_value(isAnglerUp);
        }

        pros::delay(LOOP_DURATION);
    }
}

