#include "main.h"
#include "auto.hpp" 

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {} 


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
void opcontrol() {
	setup();
	claw_mtr.set_encoder_units(MOTOR_ENCODER_DEGREES);
	claw_mtr.move_absolute(175,100);


	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

		int rightval = (master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_RIGHT_X)/2);
		int leftval = (master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_X)/2);
		left1_mtr.move_velocity(leftval);
		left2_mtr.move_velocity(leftval);
		right1_mtr.move_velocity(-rightval);
		right2_mtr.move_velocity(-rightval);

		

		if (master.get_digital(DIGITAL_R1)){
			if (lift_mtr.get_position()<800){
				lift_mtr.move_velocity(70);
			}
			else{
				lift_mtr.brake();
			}
		}
		else if (master.get_digital(DIGITAL_R2)){
			if (lift_mtr.get_position()>20){
				lift_mtr.move_velocity(-50);
			}
			else{
				lift_mtr.brake();
			}
		}

		else{
			lift_mtr.move_velocity(0);
		}

//////////////////////////////////////////////////////////////
			if (master.get_digital(DIGITAL_L2)){
				claw_mtr.move_absolute(90,100);
			}
			else if (master.get_digital(DIGITAL_L1)){
				claw_mtr.move_absolute(175,100);
			}
		// if (master.get_digital(DIGITAL_L1)){
		// 	if (claw_mtr.get_position()<160){
		// 		claw_mtr.move_velocity(70);
		// 	}
		// 	else{
		// 		claw_mtr.brake();
		// 	}
		// }
		// else if (master.get_digital(DIGITAL_L2)){
		// 	if (claw_mtr.get_position()>10){
		// 		claw_mtr.move_velocity(-50);
		// 	}
		// 	else{
		// 		claw_mtr.brake();
		// 	}
		// }
		// else{
		// 	claw_mtr.brake();
		// }



		if (master.get_digital(DIGITAL_A) && master.get_digital(DIGITAL_B)){
			autonomous();
		}

		
		
		pros::delay(20);
	}
}

