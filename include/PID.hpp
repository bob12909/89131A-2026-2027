#pragma once
#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
#include <math.h>

// this is where i delcared all the functions and variables that are used in the PID.cpp
void PID(double deg);
void odom(double xd, double yd);
void lift(double hieght);
void dlift(double hieght);
void drivey(double inches);

extern double ki;
extern double kp;
extern double kd;

extern double wheel;
extern double prev_hieght;
extern double up;