#include "main.h"

//AUTONOMOUS CONSTANTS
////PID ROTATIONAL CONSTANTS
extern const double ROTATIONAL_MINIMUM_DERIVATIVE;
extern const int ROTATIONAL_ERROR_EXIT;
extern const int ROTATIONAL_DERIVATIVE_EXIT;
////PID TRANSLATION CONSTANTS
extern const double TRANSLATIONAL_MINIMUM_DERIVATIVE;
extern const int TRANSLATIONAL_DERIVATIVE_EXIT;
//PRECISION CONSTANTS
extern const int ANALOG_DEAD_ZONE;
extern const int ROTATION_PRECISION;
extern const int TRANSLATION_PRECISION;

//DURATION  CONSTANTS
//https://www.vexforum.com/t/v5-distance-sensor-technical-details/88482/8
//DISTANCE SENSOR FREQUENCY IS ~30 HZ: jpearman
extern const int LOOP_DURATION;
extern const int DISTANCE_SENSOR_DELAY;

//MOTOR CONSTANTS
extern const int MAX_VOLTAGE;







