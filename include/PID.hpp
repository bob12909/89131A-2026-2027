#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
#include <math.h>
#include "subsystem.hpp"
#pragma once

const double PI = 3.14159265358979323846;
double ki = 0;
double kp = 0;
double kd = 0;
double wheel = 2 * PI * 1.375;
void PID(double deg) {
    ki = 0.01;
    kp = 3;
    kd = 12;
	//the tare for our imu sets everything to 0 so we can easily go our requested amount of degrees 
    Bob.tare();
    pros::delay(5);
    // the previous error helps our PID with derivitive because you need to get whatever your current error is by getting your requested amount of degrees and subtracting your curent heading
    double preverror = 0;
    // this is setting a variable for the future when we add our current error to our integral
    double integral = 0;
	// this bool tells the code wether to run auton or not
    bool turn = true;
    while (turn) {
		// this is when we get our error so we know how far to turn
        double error = deg - Bob.get_heading();

        // normalize to [-180, 180]
        if (error > 180) error -= 360;
        if (error < -180) error += 360;
		// this checks if we have reached our requested degree and stops if we have
        if (fabs(error) < 1) {
            turn = false;
            break;
        }
		//this is the math it get our integral and our derivative
		integral = integral + error;
        double derivative = error - preverror;
        preverror = error;
		//this is where we do the math on how much the motor needs to move
        double power = error * kp + integral * ki + derivative * kd;

        lefty.move(power);
        righty.move(-power);

        pros::delay(15);
    }
	//this is where the motors just stop because everything done
    lefty.move(0);
    righty.move(0);
}
void odom(double xd,double yd) {
    kp = 3;
    ki = 0.01;
    kd = 12;
    y.reset_position();
    x.reset_position();
    while (true) {
        //
        double xerror = xd - (x.get_position()/36000)* wheel;
        double yerror = yd - (y.get_position()/36000)* wheel;
        //
        double dist_error = sqrt(xerror*xerror + yerror*yerror);
        double angle = (180/PI)*atan2(xerror,yerror);
        //
        double lat = dist_error * kp;
        //
        double left = lat - angle;
        double right = lat + angle;
        //
        lefty.move(left);
        righty.move(right);
    }
}
double up = 1;
double prev_hieght = 0;
void lift(double hieght){
    kp = 4;
    ki =0.01;
    kd = 12;
    // the previous error helps our PID with derivitive because you need to get whatever your current error is by getting your requested amount of degrees and subtracting your curent heading
    double preverror1 = 0;
    double preverror2 = 0;
    // this is setting a variable for the future when we add our current error to our integral
    double integral1 = 0;
    double integral2 = 0;
    bool lift = true;
    while (lift) {
        //
        double current1 = pros::c::motor_get_position(6);
        double current2 = pros::c::motor_get_position(8);
        current2 /= 7;
        current1 /= 7;
        
        //
        double error1;
        double error2;
        error1 = hieght - current1;
        error2 = hieght - current2;

        if (fabs(error1) < 1) {
            lift = false;
            break;
        }
        if (fabs(error2) < 1) {
            lift = false;
            break;
        }
        //
        integral1 += error1;
        integral2 += error2;
        double derivative1 = error1 - preverror1;
        double derivitave2 = error2 - preverror2;
        //
        double power1 = error1 * kp + integral1 * ki + derivative1 * kd;
        double power2 = error2 * kp + integral2 * ki + derivitave2 * kd;
        //
        lift1.move(power1);
        lift2.move(power2);
    
    }
}
void dlift(double hieght){
    kp = 4;
    ki =0.01;
    kd = 12;
    // the previous error helps our PID with derivitive because you need to get whatever your current error is by getting your requested amount of degrees and subtracting your curent heading
    double preverror1 = 0;
    double preverror2 = 0;
    // this is setting a variable for the future when we add our current error to our integral
    double integral1 = 0;
    double integral2 = 0;
    bool lift = true;
    while (lift) {
        //
        double current1 = pros::c::motor_get_position(6);
        double current2 = pros::c::motor_get_position(8);
        current2 /= 7;
        current1 /= 7;
        
        //
        double error1;
        double error2;
        error1 = current1 - hieght;
        error2 = current2 - hieght;

        if (fabs(error1) < 1) {
            lift1.move(0);
            lift = false;
            break;
        }
        if (fabs(error2) < 1) {
            lift2.move(0);
            lift = false;
            break;
        }
        //
        integral1 += error1;
        integral2 += error2;
        double derivative1 = preverror1 - error1;
        double derivitave2 = preverror2 - error2;
       
        //
        double power1 = error1 * kp + integral1 * ki + derivative1 * kd;
        double power2 = error2 * kp + integral2 * ki + derivitave2 * kd;
        //
        lift1.move(-power1);
        lift2.move(power2);
        
        preverror1 = error1;
        preverror2 = error2;

        pros::delay(15);
    }
}