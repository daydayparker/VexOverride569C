#include "subsystem_headers/drive.hpp"
#include "subsystem_headers/globals.hpp"

void setDriveByDriver(){
    int leftJoystickValue = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystickValue = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if (abs(leftJoystickValue) < ANALOG_DEAD_ZONE){
        leftJoystickValue = 0;
    }
    if (abs(rightJoystickValue) < ANALOG_DEAD_ZONE){
        rightJoystickValue = 0;
    }

    chassis.tank(leftJoystickValue, rightJoystickValue);
}