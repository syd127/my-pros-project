#include "main.h"
#include "isetting.hpp"
#include "cmath"

const double circumfrence = 4*3.14159265;
const double matSize = 23.4166;

void movefwd(double mat){

    mat = mat*matSize/(circumfrence);
    mat = mat*(2.0/3);

    right1_mtr.move_relative(mat,100);
    right2_mtr.move_relative(mat,100);
    left1_mtr.move_relative(-mat,100);
    left2_mtr.move_relative(-mat,100);
}

void movebk(double mat){

    mat = mat*matSize/(circumfrence);
    mat = mat*(2.0/3);

    right1_mtr.move_relative(-mat,100);
    right2_mtr.move_relative(-mat,100);
    left1_mtr.move_relative(mat,100);
    left2_mtr.move_relative(mat,100);

}

void turnleft(double m){
    
    right1_mtr.move_relative(m,70);
    right2_mtr.move_relative(m,70);
    left1_mtr.move_relative(m,70);
    left2_mtr.move_relative(m,70);
}

void turnright(double m){
    right1_mtr.move_relative(-m,70);
    right2_mtr.move_relative(-m,70);
    left1_mtr.move_relative(-m,70);
    left2_mtr.move_relative(-m,70);
}

void liftmove(double num){

    if (num == 1){
        lift_mtr.move_absolute(44, 70);
        while (!((lift_mtr.get_position() > 40) && (lift_mtr.get_position() < 47))) {
            pros::delay(2);
        }
    }
    else if (num == 2){

        lift_mtr.move_absolute(70, 70);
        while (!((lift_mtr.get_position() > 65) && (lift_mtr.get_position() < 75))) {
            pros::delay(2);
        }
    }
    else if (num == 3){
        lift_mtr.move_absolute(595, 70);
        while (!((lift_mtr.get_position() > 590) && (lift_mtr.get_position() < 600))) {
            pros::delay(2);
        }
    }
    
}

void clawmove(double clmun){

    if (clmun == 1){// down
        claw_mtr.move_absolute(40,70);
        while (!((claw_mtr.get_position() > 35) && (claw_mtr.get_position() < 45))) {
            pros::delay(2);
        }
    }
    else if (clmun == 0){
        claw_mtr.move_absolute(175,70);
        while (!((claw_mtr.get_position() > 170) && (claw_mtr.get_position() < 180))) {
            pros::delay(2);
        }
    }

}




/**n
 * 
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
void autonomous1() {
    right1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    right2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);

    
    movefwd(3);// one
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(1.5);
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(2);//two
    pros::delay(3000);
    movebk(0.2);
    pros::delay(1000);
    turnleft(0.62);
    pros::delay(3000);
    movefwd(1.5);
    pros::delay(3000);
    turnleft(0.62);
    pros::delay(3000);
    movefwd(2);// three
    pros::delay(3000);
}

void autonomous2(){
    right1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    right2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);

    lift_mtr.set_encoder_units(MOTOR_ENCODER_DEGREES);
    lift_mtr.tare_position();

    claw_mtr.set_encoder_units(MOTOR_ENCODER_DEGREES);

    movefwd(4);// push red
    pros::delay(3000);
    liftmove(1);
    pros::delay(3000);
    turnleft(0.62);
    pros::delay(3000);
    movebk(5);
    pros::delay(3000);
    clawmove(1);
    pros::delay(3000);
    liftmove(2);// get blue
    pros::delay(3000);
    movefwd(1);
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(3);// push up yellow
    pros::delay(3000);
    turnleft(0.62);
    pros::delay(3000);
    clawmove(0);
    pros::delay(3000);
    liftmove(1);// put blue
    pros::delay(3000);
    movefwd(1.5);
    pros::delay(3000);
    turnleft(0.62);
    pros::delay(3000);
    movefwd(2);// push tall
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(1.5);
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(3);// push close
    pros::delay(3000);

}

void autonomous3(){// bad
    right1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    right2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left1_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
    left2_mtr.set_encoder_units(MOTOR_ENCODER_ROTATIONS);

    lift_mtr.set_encoder_units(MOTOR_ENCODER_DEGREES);
    lift_mtr.tare_position();
    
    liftmove(1);
    movefwd(4);// red one
    pros::delay(3000);
    movebk(0.2);
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(1);
    pros::delay(3000);
    turnleft(0.62);
    pros::delay(3000);
    movefwd(2.5);// y1
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(1.5);
    pros::delay(3000);
    turnright(0.62);
    pros::delay(3000);
    movefwd(2.5);//y2
    pros::delay(3000);
    turnleft(0.62);
    pros::delay(3000);
    movefwd(1); 
    pros::delay(3000);
    pros::delay(3000);

}


 
