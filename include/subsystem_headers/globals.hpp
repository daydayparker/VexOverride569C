#include "main.h"

//CONTROLLER
extern pros::Controller controller;

//INERTIAL MEASUREMENT UNIT
extern pros::Imu inertialSensor;

//MOTORS
////CASCADE MOTORS
extern pros::MotorGroup cascadeMotorGroup;

////DRIVE MOTORS
extern pros::MotorGroup allDriveMotorGroup;
extern pros::MotorGroup leftDriveMotorGroup;
extern pros::MotorGroup rightDriveMotorGroup;

////INTAKE MOTOR
extern pros::Motor intakeMotor;

//PNEUMATICS
extern pros::adi::DigitalOut anglerPneumatic;
extern pros::adi::DigitalOut clawPneumatic;

//ROTATION SENSORS
extern pros::Rotation anglerRotationSensor;
extern pros::Rotation horizontalRotationSensor;
extern pros::Rotation verticalRotationSensor;