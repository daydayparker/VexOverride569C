#include "main.h"

//CONSTANTS
const int DRIVETRAIN_RPM = 450;
const float HORIZONTAL_TRACKING_WHEEL_OFFSET = 0;
const float TRACK_WIDTH = 11.0;
const float VERTICAL_TRACKING_WHEEL_OFFSET = 0;
const float WHEELBASE_DISTANCE = 13.5;

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//INERTIAL MEASUREMENT UNIT
pros::Imu inertialSensor(19);

//MOTORS
////CASCADE MOTORS
//////{LEFT, RIGHT}
pros::MotorGroup cascadeMotorGroup(
    {-2, 4},
    pros::v5::MotorGears::green, 
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
    {1, -9},
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);


//ROTATION SENSORS
pros::Rotation horizontalRotationSensor(-20);
pros::Rotation verticalRotationSensor(10);

//LEMLIB
////DRIVETRAIN
lemlib::Drivetrain drivetrain(&leftDriveMotorGroup,
                              &rightDriveMotorGroup, // right motor group
                              TRACK_WIDTH, // 10 inch track width
                              lemlib::Omniwheel::NEW_325, // using new 4" omnis
                              DRIVETRAIN_RPM, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

////TRACKING WHEELS
lemlib::TrackingWheel horizontalTrackingWheel(&horizontalRotationSensor,
                                              lemlib::Omniwheel::NEW_2,
                                              HORIZONTAL_TRACKING_WHEEL_OFFSET
);
lemlib::TrackingWheel verticalTrackingWheel(&verticalRotationSensor,
                                            lemlib::Omniwheel::NEW_2,
                                            VERTICAL_TRACKING_WHEEL_OFFSET
);

////SENSORS
lemlib::OdomSensors sensors(&verticalTrackingWheel,
                            nullptr,
                            &horizontalTrackingWheel,
                            nullptr,
                            &inertialSensor
);

////CONTROLLER SETTINGS
lemlib::ControllerSettings lateralController(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

////CHASSIS
lemlib::Chassis chassis(drivetrain,
                        lateralController,
                        angularController,
                        sensors
);