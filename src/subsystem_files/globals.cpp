#include "main.h"

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//INERTIAL MEASUREMENT UNIT
pros::Imu inertialSensor(7);

//MOTORS
////CASCADE MOTORS
//////{LEFT, RIGHT}
pros::MotorGroup cascadeMotorGroup(
    {-2, 4},
    pros::v5::MotorGears::green, 
    pros::v5::MotorUnits::degrees
);

////DRIVE MOTORS
//////{LEFTFRONT, LEFTBACK, RIGHTFRONT, RIGHTBACK}
//////{FRONT, BACK}
//////{FRONT, BACK}
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
pros::Motor intakeMotor(
    1,
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);

//PNEUMATICS
pros::adi::DigitalOut anglerPneumatic('A');
pros::adi::DigitalOut clawPneumatic('B');

//ROTATION SENSORS
pros::Rotation anglerRotationSensor(5);
pros::Rotation horizontalRotationSensor(16);
pros::Rotation verticalRotationSensor(7);