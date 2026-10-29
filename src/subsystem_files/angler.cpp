#include "subsystem_headers/angler.hpp"
#include "subsystem_headers/globals.hpp"


void anglerLoop(void*){
    while (true)
    {
        if (!macroRunning)
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
            //LOWER: HOLD
            case 0:
                anglerMotor.move(MAX_VOLTAGE);
                break;
            //RAISE: HOLD
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
        }

        pros::delay(LOOP_DURATION);
    }

}