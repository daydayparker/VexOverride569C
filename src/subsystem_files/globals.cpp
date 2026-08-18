#include "main.h"

//DRIVE MOTORS
//{LEFTFRONT, LEFTBACK, RIGHTFRONT, RIGHTBACK}
//{FRONT, BACK}
//PORT NUMBERS NEED TO BE DECIDED
//REVERSED MOTORS NEED TO BE FIGURED OUT
pros::MotorGroup allDriveMotorGroup(
    {-1, -2, 3, 4}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);
pros::MotorGroup leftDriveMotorGroup(
    {-1, -2}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);
pros::MotorGroup rightDriveMotorGroup(
    {3, 4}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//INTAKE MOTOR
pros::Motor intakeMotor(
    5, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);