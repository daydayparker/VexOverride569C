#include "subsystem_headers/autons.hpp"
#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"

void closeWallClosePin(){
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

void closeWallFarPin(){
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

void farWallClosePin(){
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

void farWallFarPin(){
    //PART 1
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 12, 1000);

    //PART 2
    chassis.moveToPose(0, 0, -90, 1000);
    intakeMotorGroup.move(-MAX_VOLTAGE);

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
}

void skillsAuton(){
    
}

void testAuton(){
    //CALIBRATES THE POSITION
    chassis.setPose(0, 0, 0);

    //SETS ROBOT TO 90 DEGREES
    //chassis.turnToHeading(90, 1000);

    //TRANSLATES THE ROBOT
    chassis.moveToPoint(0, 36, 100000);
}