#include "main.h"

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left1_mtr(11);
	pros::Motor right1_mtr(1);
	pros::Motor right2_mtr(10);
	pros::Motor left2_mtr(20);
	pros::Motor lift_mtr(4, pros::E_MOTOR_GEARSET_36, 0, pros::E_MOTOR_ENCODER_DEGREES);
	pros::Motor claw_mtr(2);


void setup(){
	lift_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
	claw_mtr.set_brake_mode(MOTOR_BRAKE_BRAKE);
	lift_mtr.tare_position();
	claw_mtr.tare_position();
}