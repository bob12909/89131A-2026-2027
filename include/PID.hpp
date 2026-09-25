#pragma once
#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"
#include <math.h>
#include "subsystem.hpp"
// =========================
// PID FUNCTIONS
// =========================

void PID(double deg);
void odom(double xd, double yd);
void lift(double hieght);
void dlift(double hieght);

// =========================
// PID VARIABLES
// =========================

extern double ki;
extern double kp;
extern double kd;

extern double wheel;
extern double prev_hieght;
extern double up;