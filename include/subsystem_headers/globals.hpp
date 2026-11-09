#ifndef GLOBALS
#define GLOBALS

#include "main.h"
#include "lemlib/api.hpp"

//CONSTANTS
const int DRIVETRAIN_RPM = 450;
const float HORIZONTAL_TRACKING_WHEEL_OFFSET = 0;
const float TRACK_WIDTH = 11.0;
const float VERTICAL_TRACKING_WHEEL_OFFSET = 0;
const float WHEELBASE_DISTANCE = 13.5;

//CONTROLLER
extern pros::Controller controller;

//INERTIAL MEASUREMENT UNIT
extern pros::Imu inertialSensor;

//MOTORS
////CASCADE MOTORS
extern pros::MotorGroup cascadeMotorGroup;

////CLAW MOTOR
extern pros::Motor anglerMotor;

////DRIVE MOTORS
extern pros::MotorGroup allDriveMotorGroup;
extern pros::MotorGroup leftDriveMotorGroup;
extern pros::MotorGroup rightDriveMotorGroup;

////INTAKE MOTOR
extern pros::MotorGroup intakeMotorGroup;

//ROTATION SENSORS
extern pros::Rotation horizontalRotationSensor;
extern pros::Rotation verticalRotationSensor;

//LEMLIB
////CONTROLLER SETTINGS
extern lemlib::ControllerSettings lateralController;
extern lemlib::ControllerSettings angularController;

////DRIVETRAIN
extern lemlib::Drivetrain drivetrain;

////TRACKING WHEELS
extern lemlib::TrackingWheel horizontalTrackingWheel;
extern lemlib::TrackingWheel verticalTrackingWheel;

////EXPO DRIVE CURVES
extern lemlib::ExpoDriveCurve throttleCurve;
extern lemlib::ExpoDriveCurve steerCurve;

////CHASSIS
extern lemlib::Chassis chassis;

#endif