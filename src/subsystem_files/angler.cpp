#include "main.h"

void anglerLoop(void*){
    while (true)
    {
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
		{
			anglerState = 0;
		}
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
            anglerState = 1;
        }
        else{
            anglerState = 2;
        }
        
        switch (anglerState)
        {
        //CLOSE: HOLD
        case 0:
            anglerMotor.move(MAX_VOLTAGE);
            break;
        //OPEN: HOLD
        case 1:
            anglerMotor.move(-MAX_VOLTAGE);
            break;
        //STOP ANGLER MOTOR
        case 2:
            anglerMotor.move(0);
            break;
        default:
            anglerMotor.move(0); 
            break;  
        }

        pros::delay(LOOP_DURATION);
    }

}