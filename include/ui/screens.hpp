#pragma once

#include "liblvgl/lvgl.h"
#include <string>
#pragma once
//this is where i declared all of the screens we used on the vex brain and where we got variables from screen.cpp to other files
extern lv_color_t  bc1;
extern lv_color_t  bc2;
extern double auton_select;
extern std::string name;
namespace Screens {
    void init();
    void show_main();
    void show_auton();
    void show_settings();
    void show_motors();
    void show_debug();
    void show_auton2();
    void show_drive();
    void show_skills();
}