#include "subsystem_headers/autons.hpp"
#include "subsystem_headers/globals.hpp"

void leftMatchAuton(){

}

void rightMatchAuton(){
    
}

void soloMatchAuton(){

}

void skillsAuton(){
    
}

void testAuton(){
    //CALIBRATES THE POSITION
    chassis.setPose(0, 0, 0);

    //SETS ROBOT TO 90 DEGREES
    //chassis.turnToHeading(90, 100000);

    //TRANSLATES THE ROBOT
    chassis.moveToPoint(0, 48, 100000);
}