#include "main.h"

//CASCADE MOTORS
//{RIGHT, LEFT}
//CHECK IF THIS IS THE RIGHT DIRECTION
pros::MotorGroup cascadeMotorGroup(
    {1, -2},
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//DRIVE MOTORS
//{LEFTFRONT, LEFTBACK, RIGHTFRONT, RIGHTBACK}
//{FRONT, BACK}
//PORT NUMBERS NEED TO BE DECIDED
//REVERSED MOTORS NEED TO BE FIGURED OUT
pros::MotorGroup allDriveMotorGroup(
    {-12, -14, 11, 13}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);
pros::MotorGroup leftDriveMotorGroup(
    {-12, -14}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);
pros::MotorGroup rightDriveMotorGroup(
    {11, 13}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//INTAKE MOTOR
//CHECK IF THIS IS THE RIGHT DIRECTION
pros::MotorGroup intakeMotorGroup(
    {5, 6},
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);