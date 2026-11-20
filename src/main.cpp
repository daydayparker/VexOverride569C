#include "main.h"
#include "subsystem_headers/autons.hpp"
#include "subsystem_headers/claw.hpp"
#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/drive.hpp"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/image.hpp"
#include "subsystem_headers/lift.hpp"
#include "subsystem_headers/toggler.hpp"

//TO-DO LIST
/*
FIX MACROS SETUP WHERE THEY CAN BE CANCELLED
SYNTAX FIXING
*/

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
/*
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
*/

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
	display_img_from_c_array();
	
	//PUT AWESOME TEXT ON THE CONTROLLER SCREEN
	controller.print(0, 0, "By: %s", "daydayparker");

	//SET MOTOR BRAKE TYPES
	allDriveMotorGroup.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
	clawMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	liftMotorGroup.set_brake_mode_all(pros::E_MOTOR_BRAKE_HOLD);
	togglerMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	//CALIBRATE MOTORS
	clawMotor.tare_position();
	liftMotorGroup.tare_position_all();
	togglerMotor.tare_position();
	chassis.calibrate();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous() {
	testAuton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol(){
	allDriveMotorGroup.set_brake_mode_all(pros::E_MOTOR_BRAKE_COAST);
	
	pros::Task clawTask(clawLoop);
	pros::Task liftTask(liftLoop);
	pros::Task togglerTask(togglerLoop);

	while (true){
		setDriveByDriver();
		pros::delay(LOOP_DURATION);
	}
}