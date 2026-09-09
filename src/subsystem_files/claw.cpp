#include "main.h"

void clawLoop(void*){
    while (true)
    {
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		{
			clawState = 0;
		}
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
            clawState = 1;
        }
        else{
            clawState = 2;
        }
        
        switch (clawState)
        {
        //CLOSE: HOLD
        case 0:
            clawMotor.move(MAX_VOLTAGE);
            break;
        //OPEN: HOLD
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

        pros::delay(LOOP_DURATION);
    }

}