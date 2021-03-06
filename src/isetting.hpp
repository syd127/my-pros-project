#include "main.h"

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left1_mtr(11);
	pros::Motor right1_mtr(1);
	pros::Motor right2_mtr(10);
	pros::Motor left2_mtr(20);
	pros::Motor lift_mtr(4, pros::E_MOTOR_GEARSET_36, 0, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor claw_mtr(2, pros::E_MOTOR_GEARSET_36, 0, pros::E_MOTOR_ENCODER_DEGREES);


void setup(){
	lift_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	claw_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);


	left1_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	left2_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	right1_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
	right2_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);


	lift_mtr.tare_position();
	claw_mtr.tare_position();

	claw_mtr.move_absolute(175,100);
	// while (!((claw_mtr.get_position() > 170) && (claw_mtr.get_position() < 180))) {
	// 	pros::delay(2);
	// }
	lift_mtr.move_absolute(40, 100);
	
	while (!((lift_mtr.get_position() > 35) && (lift_mtr.get_position() < 40))) {
		pros::delay(2);
	}
	
}