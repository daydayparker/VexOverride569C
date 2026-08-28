#include "main.h"

void cascadeLoop(void*){
    while (true)
    {
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			cascadeState = 0;
		}
        else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
            cascadeState = 1;

        }
        else{
            cascadeState = 2;
        }
        
        switch (cascadeState)
        {
        //REVERSE: HOLD
        case 0:
            cascadeMotorGroup.move(MAX_VOLTAGE);
            break;
        //STOP INTAKE
        case 1:
            cascadeMotorGroup.move(-MAX_VOLTAGE);
            break;
        //SPIN INTAKE FORWARD: TOGGLE
        case 2:
            cascadeMotorGroup.move(0);
            break;
        default:
            cascadeMotorGroup.move(0); 
            break;  
        }

        pros::delay(LOOP_DURATION);
    }
    
}