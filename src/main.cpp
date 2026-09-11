#include "PID.hpp"
#include "liblvgl/display/lv_display.h"
#include "liblvgl/lv_init.h"
#include "liblvgl/tick/lv_tick.h"
#include "profiles.hpp"
#include "pros/motors.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
#include <cstdint>
#include "main.h"
#include "ui/initalize.cpp"
#include "ui/screens.hpp"


void initialize() {
    initializeGUI();
	Themes::set(Themes::ID::BRAYDEN);
    Screens::init();
    Screens::show_auton();
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
	PID(90);
	pros::delay(5);
	PID(45);
}
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
	kenzy();
	
	while (true) {
		lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		lefty.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		righty.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    	int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		lefty.move(dir + turn);                      // Sets left motor voltage
		righty.move(dir - turn);                     // Sets right motor voltage
		pros::delay(20); 
		if (master.get_digital(DIGITAL_R2)) {
    	lift1.move(127);
		lift2.move(127);
		}
		else if (master.get_digital(DIGITAL_R1)) {
			if (pros::c::motor_get_position(6) > 100) {
				lift1.move(-127);
				lift2.move(-127);
			}
			else { 
				lift1.move(20);
				lift2.move(20);
			}
		
			if (pros::c::motor_get_position(8) > 100) {
				lift1.move(-127);
				lift2.move(-127);
			}
			else { 
				lift1.move(20);
				lift2.move(20);
			}
		}
		else if (master.get_digital(DIGITAL_L2)) {
			clawlift.move(127);
		}
		else if (master.get_digital(DIGITAL_L1)) {
			clawlift.move(-127);
		}
		else {

			clawlift.move(0);
			lift1.move(0);
			lift2.move(0);
	}
	}
}