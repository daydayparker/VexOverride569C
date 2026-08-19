#include "main.h"

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
pros::Motor intakeMotor(
    5, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);