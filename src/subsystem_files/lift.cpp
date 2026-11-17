#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/lift.hpp"
#include "subsystem_headers/states.hpp"

void liftLoop(void*){
    while (true)
    {
        if (!macroRunning)
        {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
            {
                liftState = 0;
            }
            else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
                liftState = 1;

            }
            else{
                liftState = 2;
            }
            
            switch (liftState)
            {
            //UP: HOLD
            case 0:
                liftMotorGroup.move(MAX_VOLTAGE);
                break;
            //DOWN: HOLD
            case 1:
                liftMotorGroup.move(-MAX_VOLTAGE);
                break;
            //STOP LIFT
            case 2:
                liftMotorGroup.move(0);
                break;
            default:
                liftMotorGroup.move(0); 
                break;  
            }
        }

        pros::delay(LOOP_DURATION);
    } 
}