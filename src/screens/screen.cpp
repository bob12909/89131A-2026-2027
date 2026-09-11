    #include "ui/screens.hpp"
    #include "ui/themes.hpp"
    #include "ui/buttons.hpp"
    #include "fonts.hpp"
    #include "imgs.hpp"
    #include <string>
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
    std::string name = "kenzy";
    double name_c = 0;
    std::string theme = "dark";
    void name_button(lv_event_t* event) {
        name_c += 1;
        if (name_c == 0)
        {
            name = "kenzy";
        }
        else if (name_c == 1)
        {
            name = "shyloh";
        }
        else if (name_c == 2)
        {
            name_c = 0;
            name = "kenzy";
        }
        Screens::init();
        Screens::show_main();
    }
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
         name = "dark";
        }
        else if (ID == 1)
        {
         Themes::set(Themes::ID::SHY);   
         name = "shy";
        }
        else if (ID == 2)
        {
         Themes::set(Themes::ID::KENZY);   
         name = "kenzy";
        }
        else if (ID == 3)
        {
         Themes::set(Themes::ID::BRAYDEN);
        name = "brayden";   
        }
        else if (ID == 4)
        {
         ID = 0;
         Themes::set(Themes::ID::DARK);   
         name = "dark";
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
        
        UI::image(
            main_screen,
            &bg1,
            0,
            0
        );
        UI::panel(
            main_screen,
            140,
            280,
            0,
            0
        );
        lv_obj_t * title = UI::panel(
            main_screen,
            120,
            30,
            10,
            10
        );
        UI::background(
            title,
            lv_color_hex(0x555555)
        );
         UI::label(
         main_screen,
         "89131A",
         11,
         13,
         &courier_new_32
        );
        lv_obj_t * autona_button = UI::create_button(
            main_screen,
            "AUTON",
            10,
            45,
            120,
            40,
            auton_button
        );
        UI::font(
            autona_button,
            &courier_new_bold_
        );
        lv_obj_t * motorss_button = UI::create_button(
            main_screen,
            "MOTORS",
            10,
            90,
            120,
            40,
            motors_button
        );
        UI::font(
            motorss_button,
            &courier_new_bold_
        );
        lv_obj_t * controller_panel = UI::panel(
            main_screen,
            130,
            20,
            5,
            135
        );
        UI::background(
            controller_panel,
            lv_color_hex(0x555555)
        );
        UI::label(
         main_screen,
         "CONTROLLER",
         8,
         136,
         &courier_new_20
        );
        lv_obj_t * namee_button = UI::create_button(
         main_screen,
         name.c_str(),
         10,
         160,
         120,
         40,
         name_button
        );
        UI::font(
            namee_button,
            &courier_new_24
        );  
        UI::background(
            namee_button,
            UI::gradient(
                lv_color_hex(0x555555),
                lv_color_hex(0xaaaaaa)
        );     
        lv_obj_t * settingss_button = UI::create_button(
            main_screen,
            "SETTINGS",
            10,
            200,
            120,
            40,
            settings_button
        );
        UI::font(
            settingss_button,
            &courier_new_24
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