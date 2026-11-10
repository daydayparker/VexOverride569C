#include "subsystem_headers/image.hpp"
#include "liblvgl/core/lv_obj_pos.h"
#include "liblvgl/display/lv_display.h"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/misc/lv_types.h" 
#include "liblvgl/widgets/image/lv_image.h"

void display_img_from_c_array(){
	// create a variable for the c array (image)
	LV_IMAGE_DECLARE(humanoid_robot_image);

	// declare and define the image object
	lv_obj_t* img = lv_image_create(lv_screen_active());

	// set the source data for the image
	lv_image_set_src(img, &humanoid_robot_image);

	//align image
	lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
}