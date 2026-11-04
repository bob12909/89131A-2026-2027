#include "pros/misc.h"
#include "subsystem.hpp"

int counter = 0;
void kenzy() {
		if (master.get_digital(DIGITAL_L2)) {
    	lift1.move(127);
		clawlift.move_absolute(-1000, 127);
		}
		else if (master.get_digital(DIGITAL_L1)) {
			lift1.move(-127);
			
		}
        else if (master.get_digital(DIGITAL_R2)) {
			intake_claw.move(127);
			intake.move(127);
		}
        else if (master.get_digital(DIGITAL_R1)) {
			intake_claw.move(-127);
			intake.move(-127);
		}
		else if (master.get_digital(DIGITAL_B)) {
			clawlift.move_absolute(0, 127);
			
		}
		else if (master.get_digital(DIGITAL_Y)) {
			clawlift.move(-127);
		}
		else if (master.get_digital(DIGITAL_RIGHT)) {
			intake_pistion.set_value(1);
		}
		else if (master.get_digital(DIGITAL_LEFT)) {
			intake_pistion.set_value(0);
		}
		else {

			clawlift.move(0);
			lift1.move(0);
            intake_claw.move(0);
			intake.move(0);
			
	}
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		lefty.move(dir - turn);                      // Sets left motor voltage
		righty.move(-dir - turn);                     // Sets right motor voltage
		pros::delay(20);
}
void shyloh() {
    	if (master.get_digital(DIGITAL_L2)) {
    	lift1.move(127);
		clawlift.move_absolute(-1000, 127);
		
		}
		else if (master.get_digital(DIGITAL_R2)) {
			lift1.move(-127);
			clawlift.move_absolute(0, 127);
		}
        else if (master.get_digital(DIGITAL_L1)) {
			intake_claw.move(127);
		}
        else if (master.get_digital(DIGITAL_R1)) {
			intake_claw.move(-127);
		}
		else if (master.get_digital(DIGITAL_Y)) {
			clawlift.move(-127);
		}
		else if (master.get_digital(DIGITAL_RIGHT)) {
			clawlift.move_absolute(0, 127);
		}
		else if (master.get_digital(DIGITAL_B)) {
			intake_claw.move(127);
			intake.move(127);
		}
        else if (master.get_digital(DIGITAL_DOWN)) {
			intake_claw.move(-127);
			intake.move(-127);
		}
		else {

			clawlift.move(0);
			lift1.move(0);
            intake_claw.move(0);
			intake.move(0);
			
	}
	int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		lefty.move(-dir - turn);                      // Sets left motor voltage
		righty.move(dir - turn);                     // Sets right motor voltage
		pros::delay(20);
	}

