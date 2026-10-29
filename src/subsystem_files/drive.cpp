#include "main.h"

const int ANALOG_DEAD_ZONE = 20;

void setDrive(int left, int right){
    chassis.tank(left, right);
}

void setDriveByDriver(){
    int leftJoystickValue = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystickValue = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    if (abs(leftJoystickValue) < ANALOG_DEAD_ZONE){
        leftJoystickValue = 0;
    }
    if (abs(rightJoystickValue) < ANALOG_DEAD_ZONE){
        rightJoystickValue = 0;
    }
    setDrive(leftJoystickValue, rightJoystickValue);
}