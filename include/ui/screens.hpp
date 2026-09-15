#pragma once

#include "liblvgl/lvgl.h"
#pragma once

extern double auton_select;
namespace Screens {
    void init();
    void show_main();
    void show_auton();
    void show_settings();
    void show_motors();
    void show_debug();
    void show_auton2();
}