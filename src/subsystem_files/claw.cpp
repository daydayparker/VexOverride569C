#include "main.h"

void clawLoop(void*) {
    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
            {
                isClawClosed = !isClawClosed;
            }
        
            clawPneumatic.set_value(isClawClosed);
        }

        pros::delay(LOOP_DURATION);
    }
}