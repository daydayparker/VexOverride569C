#include "subsystem_headers/globals.hpp"
#include "subsystem_headers/testing.hpp"


void testHorizontalRotationSensor(void*){
    while (true)
    {
	    controller.print(0, 0, "HRS: %s", horizontalRotationSensor.get_position());
    }
}

void testVerticalRotationSensor(void*){

}