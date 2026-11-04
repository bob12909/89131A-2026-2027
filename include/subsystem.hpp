#include "main.h"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/motor_group.hpp"
#pragma once

inline pros::adi::DigitalOut intake_pistion('B');
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Imu Bob( 13);
inline pros::MotorGroup lefty({15, 1}); 
inline pros::MotorGroup righty({16, 17});
inline pros::Rotation x(20);
inline pros::Rotation y(21);
inline pros::MotorGroup lift1({-6,7});
inline pros::Motor intake_claw(8);
inline pros::Motor clawlift(5);
inline pros::Motor intake(14);