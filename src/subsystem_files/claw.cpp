#include "main.h"

void clawLoop(void*) {
    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
            {
                isClawOpen = !isClawOpen;
            }
        
            clawPneumatic.set_value(isClawOpen);
        }

        pros::delay(LOOP_DURATION);
    }
}