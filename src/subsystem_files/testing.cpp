#include "pros/rtos.hpp"
#include "subsystem_headers/constants.hpp"
#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/testing.hpp"


void horizontalRotationSensorValueLoop(void*){
    while (true)
    {
	    controller.print(0, 0, "HRS: %d", horizontalRotationSensor.get_position());
        pros::delay(LOOP_DURATION);
	    controller.print(0, 0, "");
		pros::delay(9 * LOOP_DURATION);
    }
}


void verticalRotationSensorValueLoop(void*){
    while (true)
    {
	    controller.print(0, 0, "VRS: %d", verticalRotationSensor.get_position());
		pros::delay(LOOP_DURATION);
	    controller.print(0, 0, "");
		pros::delay(9 * LOOP_DURATION);
    }
}