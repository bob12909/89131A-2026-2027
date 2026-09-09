#include "ui/screens.hpp"
#include "ui/themes.hpp"
#include "ui/buttons.hpp"
void settings(lv_event_t* event) {
    Screens::show_settings();
}
void main(lv_event_t* event) {
    Screens::show_main();
}
void Screens::show_main() {
lv_obj_t* screen = lv_screen_active();

    UI::create_button(
        screen,
        "settings",
        20,
        50,
        200,
        60,
        settings
    );}

void Screens::show_auton() {
    lv_obj_t* screen = lv_screen_active();
    
    UI::create_button(
        screen,
        "main",
        20,
        50,
        200,
        60,
        main
    );
}

void Screens::show_settings() {
    // We'll create the settings screen here
}

void Screens::show_motors() {
    // We'll create the motors screen here
}