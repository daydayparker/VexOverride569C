#include "main.h"

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//INERTIAL MEASUREMENT UNIT
pros::Imu inertialSensor(7);

//MOTORS
////CASCADE MOTORS
//////{LEFT, RIGHT}
pros::MotorGroup cascadeMotorGroup(
    {2, -4},
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

////ANGLER MOTOR
pros::Motor anglerMotor(
    6,
    pros::v5::MotorGears::blue,
    pros::v5::MotorUnits::degrees
);

////DRIVE MOTORS
//////{LEFTFRONT, LEFTBACK, RIGHTFRONT, RIGHTBACK}
//////{FRONT, BACK}
//////{FRONT, BACK}
//////PORT NUMBERS NEED TO BE DECIDED
pros::MotorGroup allDriveMotorGroup(
    {-12, -15, 11, 13}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);
pros::MotorGroup leftDriveMotorGroup(
    {-12, -15}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);
pros::MotorGroup rightDriveMotorGroup(
    {11, 13}, 
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

////INTAKE MOTOR
//////{NEEDS DESCRIPTION OF MOTORS}
pros::MotorGroup intakeMotorGroup(
    {1, -8},
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//ROTATION SENSORS
pros::Rotation anglerRotationSensor(5);
pros::Rotation horizontalRotationSensor(16);
pros::Rotation verticalRotationSensor(7);