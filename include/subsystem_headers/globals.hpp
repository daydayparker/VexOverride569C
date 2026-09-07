#include "main.h"

//CONTROLLER
extern pros::Controller controller;

//INERTIAL MEASUREMENT UNIT
extern pros::Imu inertialSensor;

//INERTIAL MEASUREMENT UNIT
//MOTORS
////CASCADE MOTORS
extern pros::MotorGroup cascadeMotorGroup;

////CLAW MOTOR
extern pros::Motor clawMotor;

////DRIVE MOTORS
extern pros::MotorGroup allDriveMotorGroup;
extern pros::MotorGroup leftDriveMotorGroup;
extern pros::MotorGroup rightDriveMotorGroup;

////INTAKE MOTOR
extern pros::MotorGroup intakeMotorGroup;

//ROTATION SENSORS
extern pros::Rotation anglerRotationSensor;
extern pros::Rotation horizontalRotationSensor;
extern pros::Rotation verticalRotationSensor;