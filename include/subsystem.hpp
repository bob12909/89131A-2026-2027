#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#pragma once

inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Imu Bob( 19);
inline pros::MotorGroup lefty({-15, -1, 3}); 
inline pros::MotorGroup righty({-9,16, 10});
inline pros::Rotation x(20);
inline pros::Rotation y(21);
inline pros::Motor lift1(-6);
inline pros::Motor lift2(8);
inline pros::Motor clawlift(5);
inline pros::Motor claw(5);