    #include "ui/screens.hpp"
    #include "ui/themes.hpp"
    #include "ui/buttons.hpp"

    namespace {

        lv_obj_t* main_screen;
        lv_obj_t* auton_screen;
        lv_obj_t* settings_screen;
        lv_obj_t* motors_screen;

    }

    // -------------------------
    // Button callbacks
    // -------------------------

    void settings_button(lv_event_t* event) {
        Screens::show_settings();
    }

    void main_button(lv_event_t* event) {
        Screens::show_main();
    }

    void auton_button(lv_event_t* event) {
        Screens::show_auton();
    }

    void motors_button(lv_event_t* event) {
        Screens::show_motors();
    }

    // -------------------------
    // Initialize screens
    // -------------------------

    void Screens::init() {

        main_screen = lv_obj_create(NULL);
        auton_screen = lv_obj_create(NULL);
        settings_screen = lv_obj_create(NULL);
        motors_screen = lv_obj_create(NULL);


        // =========================
        // MAIN SCREEN
        // =========================

        UI::create_button(
            main_screen,
            "AUTON",
            20,
            50,
            200,
            60,
            auton_button
        );

        UI::create_button(
            main_screen,
            "SETTINGS",
            20,
            120,
            200,
            60,
            settings_button
        );

        UI::create_button(
            main_screen,
            "MOTORS",
            20,
            190,
            200,
            40,
            motors_button
        );


        // =========================
        // AUTON SCREEN
        // =========================

        UI::create_button(
            auton_screen,
            "MAIN",
            20,
            50,
            200,
            60,
            main_button
        );
        


        // =========================
        // SETTINGS SCREEN
        // =========================

        UI::create_button(
            settings_screen,
            "MAIN",
            20,
            50,
            200,
            60,
            main_button
        );


        // =========================
        // MOTORS SCREEN
        // =========================

        UI::create_button(
            motors_screen,
            "MAIN",
            20,
            50,
            200,
            60,
            main_button
        );
    }


    // -------------------------
    // Screen switching
    // -------------------------

    void Screens::show_main() {
        lv_screen_load(main_screen);
    }

    void Screens::show_auton() {
        lv_screen_load(auton_screen);
    }

    void Screens::show_settings() {
        lv_screen_load(settings_screen);
    }

    void Screens::show_motors() {
        lv_screen_load(motors_screen);
    }