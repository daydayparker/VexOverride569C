#include "subsystem_headers/globals.hpp"

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
    16,
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
pros::MotorGroup intakeMotorGroup(
    {1, -9},
    pros::v5::MotorGears::blue, 
    pros::v5::MotorUnits::degrees
);


//ROTATION SENSORS
pros::Rotation horizontalRotationSensor(-20);
pros::Rotation verticalRotationSensor(10);

//LEMLIB
////CONTROLLER SETTINGS
lemlib::ControllerSettings lateralController(1, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
lemlib::ControllerSettings angularController(1.5, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in degrees
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in degrees
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

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

////EXPO DRIVE CURVES
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

////CHASSIS
lemlib::Chassis chassis(drivetrain,
                        lateralController,
                        angularController,
                        sensors
);