#include "subsystem_headers/autons.hpp"
#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"

void mLClose(){
   //PART 1
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 12, 1000);

    //PART 2
    chassis.moveToPose(0, 0, -90, 1000);

    //PART 3
    chassis.moveToPose(0, 0, 0, 0);
    
    //PART 4
    chassis.moveToPose(0, 0, 0, 0);
}

void mLFar(){
   //PART 1
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 12, 1000);

    //PART 2
    chassis.moveToPose(0, 0, -90, 1000);

    //PART 3
    chassis.moveToPose(0, 0, 0, 0);
    
    //PART 4
    chassis.moveToPose(0, 0, 0, 0);
}

void nonMLClose(){
    //PART 1
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 12, 1000);

    //PART 2
    chassis.moveToPose(0, 0, -90, 1000);

    //PART 3
    chassis.moveToPose(0, 0, 0, 0);
    
    //PART 4
    chassis.moveToPose(0, 0, 0, 0);
}

void nonMLFar(){
    //SET ORIGIN OF CHASSIS
    chassis.setPose(0, 0, 0);

    //CHANGE ROLLER COLOR
    chassis.moveToPoint(0, -6, 750, {.forwards = false}, false);
    allDriveMotorGroup.move(0.7 * MAX_VOLTAGE);
    pros::delay(250);
    chassis.moveToPoint(0, -6, 750, {.forwards = false}, false);
    allDriveMotorGroup.move(0.7 * MAX_VOLTAGE);
    pros::delay(1000);
    anglerMotor.move_relative(100, -MAX_VOLTAGE);
    pros::delay(250);

    //PART 2
    chassis.moveToPoint(20, -12, 1000, {.forwards = false}, false);
    intakeMotorGroup.move(-MAX_VOLTAGE);

    /*
    //PART 3
    intakeMotorGroup.move(0);
    cascadeMotorGroup.move_absolute(0, MAX_VOLTAGE);
    chassis.moveToPose(0, 0, 0, 0);
    cascadeMotorGroup.move_absolute(0, -MAX_VOLTAGE);
    intakeMotorGroup.move_absolute(0, MAX_VOLTAGE);
    
    //PART 4
    chassis.moveToPose(0, 0, 0, 0);
    cascadeMotorGroup.move_absolute(0, -MAX_VOLTAGE);
    intakeMotorGroup.move(-MAX_VOLTAGE);
    */
}

void skillsAuton(){
    
}

void testAuton(){
    anglerMotor.move_absolute(-1000, -MAX_VOLTAGE);
}