#include "main.h"
#include "isetting.hpp"
#include "cmath"


const double circumfrence = 4*3.14159265;
const double matSize = 23.4166;



void movefwd(double mat){

    mat = mat*matSize/(circumfrence);
    mat = mat*(2.0/3);

    right1_mtr.move_relative(mat,70);
    right1_mtr.move_relative(mat,70);
    left1_mtr.move_relative(-mat,70);
    left2_mtr.move_relative(-mat,70);

}


void turnleft(){


    right1_mtr.move_relative(2,70);
    right1_mtr.move_relative(2,70);
    left1_mtr.move_relative(2,70);
    left2_mtr.move_relative(2,70);

}
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

    right1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    right2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    movefwd(1);
    pros::delay(1000);
    turnleft();
    pros::delay(1000);



}


 
