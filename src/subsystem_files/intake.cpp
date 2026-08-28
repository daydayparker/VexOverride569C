#include "main.h"

void intakeLoop(void*){

    while (true)
    {
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
		{
			intakeState = 0;
		}
        else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
            if (intakeState == 1){
                intakeOn = true;
                intakeState = 2;
            }
            else{
                intakeOn = false;
                intakeState = 1;
            }
        }
        else if (intakeOn){
            intakeState = 2;
        }
        else{
            intakeState = 1;
        }
        
        switch (intakeState)
        {
        //REVERSE: HOLD
        case 0:
            intakeMotorGroup.move(-MAX_VOLTAGE);
            break;
        //STOP INTAKE
        case 1:
            intakeMotorGroup.move(0);
            break;
        //SPIN INTAKE FORWARD: TOGGLE
        case 2:
            intakeMotorGroup.move(MAX_VOLTAGE);
            break;
        default:
            intakeMotorGroup.move(0); 
            break;  
        }

        pros::delay(LOOP_DURATION);
    }
    
}