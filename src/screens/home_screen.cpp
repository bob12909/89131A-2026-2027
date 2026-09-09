#include "ui/themes.hpp"
#include "ui/buttons.hpp"

void settings(lv_event_t* event) {

    // Switch to drive screen later

}

void create_home_screen() {

    lv_obj_t* screen = lv_screen_active();

    UI::create_button(
        screen,
        "settings",
        20,
        50,
        200,
        60,
        settings
    );

}