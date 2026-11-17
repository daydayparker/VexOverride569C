#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/states.hpp"

void clawLoop(void*){

    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
            {
                clawState = 0;
            }
            else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
                clawState = 1;
            }
            //NEED OTHER CONDITION HERE
            //ALSO NEED TO MAKE THE DOUBLE TOGGLE THINGIE ACTUALLY WORK
            //NEED TO MAKE SURE CAN SWITCH FROM CAN GRAB TO OPEN AND VICE VERSA
            else if (clawSpinning){
                clawState = 2;
            }
 
            switch (clawState)
            {
            //REVERSE: HOLD
            case 0:
                clawMotor.move(-MAX_VOLTAGE);
                break;
            //STOP INTAKE
            case 1:
                clawMotor.move(0);
                break;
            //SPIN INTAKE FORWARD: TOGGLE
            case 2:
                clawMotor.move(MAX_VOLTAGE);
                break;
            default:
                clawMotor.move(0); 
                break;  
            }
        }

        pros::delay(LOOP_DURATION);
    } 
}