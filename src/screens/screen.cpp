    #include "ui/screens.hpp"
    #include "ui/themes.hpp"
    #include "ui/buttons.hpp"
    int ID = 0;
    namespace {

        lv_obj_t* main_screen;
        lv_obj_t* auton_screen;
        lv_obj_t* settings_screen;
        lv_obj_t* motors_screen;
        lv_obj_t* debug_screen;

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
    void theme_button(lv_event_t* event) {
        ID += 1;
        if (ID == 0)
        {
         Themes::set(Themes::ID::DARK);   
        }
        else if (ID == 1)
        {
         Themes::set(Themes::ID::SHY);   
        }
        else if (ID == 2)
        {
         Themes::set(Themes::ID::KENZY);   
        }
        else if (ID == 3)
        {
         Themes::set(Themes::ID::BRAYDEN);   
        }
        else if (ID == 4)
        {
         ID = 0;
         Themes::set(Themes::ID::DARK);   
        }
        Screens::init();
        Screens::show_settings();
        
    }
    // -------------------------
    // Initialize screens
    // -------------------------

    void Screens::init() {
        main_screen = lv_obj_create(NULL);
        auton_screen = lv_obj_create(NULL);
        settings_screen = lv_obj_create(NULL);
        motors_screen = lv_obj_create(NULL);
        debug_screen = lv_obj_create(NULL);


        // =========================
        // MAIN SCREEN
        // =========================
        UI::create_button(
            main_screen,
            "AUTON",
            10,
            10,
            200,
            60,
            auton_button
        );
        UI::create_button(
            main_screen,
            "SETTINGS",
            260,
            10,
            200,
            60,
            settings_button
        );
        UI::create_button(
            main_screen,
            "MOTORS",
            10,
            170,
            200,
            60,
            motors_button
        );
        lv_obj_t* title = UI::label(
        main_screen,
        "89131A",
        0,
        0,
        &lv_font_montserrat_48
    );

        lv_obj_set_style_text_letter_space(
            title,
            10,
            0
        );

        lv_obj_align(
            title,
            LV_ALIGN_CENTER,
            0,
            0
        );


        // =========================
        // AUTON SCREEN
        // =========================

        UI::create_button(
            auton_screen,
            "MAIN",
            10,
            10,
            50,
            50,
            main_button
        );
        



        // =========================
        // SETTINGS SCREEN
        // =========================

        UI::create_button(
            settings_screen,
            "MAIN",
            10,
            10,
            50,
            50,
            main_button
        );
        UI::create_button(
            settings_screen,
            "THEME",
            100,
            10,
            100,
            50,
            theme_button
        );


        // =========================
        // MOTORS SCREEN
        // =========================

        UI::create_button(
            motors_screen,
            "MAIN",
            10,
            10,
            50,
            50,
            main_button
        );
        UI::panel(
            motors_screen,
            150,
            100,
            100,
            25
        );
    }

    // -------------------------
    // debug
    // -------------------------

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
    void Screens::show_debug() {
        lv_screen_load(debug_screen);
    }