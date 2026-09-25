#pragma once

#include "liblvgl/lvgl.h"
#include <string>
#pragma once

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