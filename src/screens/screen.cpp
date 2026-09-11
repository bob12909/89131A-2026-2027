    #include "ui/screens.hpp"
    #include "ui/themes.hpp"
    #include "ui/buttons.hpp"
    #include "fonts.hpp"
    #include "imgs.hpp"
    #include <string>
    int ID = 0;
    namespace {

        lv_obj_t* main_screen;
        lv_obj_t* auton_screen1;
        lv_obj_t* settings_screen;
        lv_obj_t* motors_screen;
        lv_obj_t* debug_screen;
        lv_obj_t * auton_screen2;

    }

    // -------------------------
    // Button callbacks
    // -------------------------
    lv_color_t  c1 = lv_color_hex(0x8e0000);
    lv_color_t  c2 = lv_color_hex(0x400000);
    double alcc = 0;
    std::string name = "kenzy";
    double name_c = 0;
    std::string theme = "dark";
    void alc_change(lv_event_t* event){
        alcc += 1;
        if (alcc == 0)
        {
            c1 = lv_color_hex(0x8e0000);
            c2 = lv_color_hex(0x400000);
        }
        else if (alcc == 1){
            c1 = lv_color_hex(0x00008e);
            c2 = lv_color_hex(0x000040);
        }
        else if (alcc == 2) {
            alcc = 0;
            c1 = lv_color_hex(0x8e0000);
            c2 = lv_color_hex(0x400000);
        }
        Screens::init();
        Screens::show_auton2();
    }
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
    void alliance_button(lv_event_t * event){
        Screens::show_auton2();
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
        auton_screen1 = lv_obj_create(NULL);
        settings_screen = lv_obj_create(NULL);
        motors_screen = lv_obj_create(NULL);
        debug_screen = lv_obj_create(NULL);
        auton_screen2 = lv_obj_create(NULL);


        // =========================
        // MAIN SCREEN
        // =========================
        
        UI::image(
            main_screen,
            &bg1,
            0,
            0
        );
        lv_obj_t * main_panel = UI::panel(
            main_screen,
            140,
            240,
            0,
            0
        );
        UI::gradient(
            main_panel,
            lv_color_hex(0x828181),
            lv_color_hex(0x2e2e2e)
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
        UI::gradient(
        autona_button,
        lv_color_hex(0x8f8e8d),
        lv_color_hex(0xff0000)
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
        UI::gradient(
        motorss_button,
        lv_color_hex(0x8f8e8d),
        lv_color_hex(0xff0000)
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
         157,
         120,
         40,
         name_button
        );
        UI::font(
            namee_button,
            &name_font
        );  
        UI::gradient(
        namee_button,
        lv_color_hex(0Xa6a4a4),
        lv_color_hex(0X666565),
        LV_GRAD_DIR_RADIAL
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
        lv_obj_set_state(settingss_button, LV_STATE_DISABLED, true);
        UI::font(
            settingss_button,
            &courier_new_24
        );
        UI::gradient(
        settingss_button,
        lv_color_hex(0x8f8e8d),
        lv_color_hex(0x000000)
        ); 

        lv_obj_t * MB = UI::panel(
            main_screen,
            311,
            30,
            160,
            10
        );
        UI::label(
         main_screen,
         "Mechanical Bulls",
         165,
         13,
         &courier_new_32
        );
        UI::gradient(
            MB,
            lv_color_hex(0Xa6a4a4),
            lv_color_hex(0X666565),
            LV_GRAD_DIR_RADIAL
        );
        lv_obj_t * avhs = UI::panel(
            main_screen,
            270,
            30,
            180,
            45
        );
        UI::background(
            avhs,
            lv_color_hex(0xa9a9a9)
        );
        lv_obj_t * av = UI::label(
         main_screen,
         "Arbor View High School",
         193,
         48,
         &lv_font_montserrat_20
        );
        UI::text_color(
            av, 
            lv_color_hex(0xff0000)
        );
        // =========================
        // AUTON SCREEN
        // =========================
        
        lv_obj_t * back_auton1 = UI::create_button(
            auton_screen1,
            "BACK",
            10,
            200,
            460,
            40,
            main_button
        );
        UI::background(
            auton_screen1,
            lv_color_hex(0x212121)
        );
        UI::gradient(
        back_auton1,
        lv_color_hex(0x8f8e8d),
        lv_color_hex(0x2121221)
        );
        lv_obj_t * all = UI::create_button(
            auton_screen1,
            "Alliance",
            20,
            10,
            215,
            180,
            alliance_button
        );
        UI::font(
            all,
            &courier_new_24
        );
        UI::gradient(
            all,
            lv_color_hex(0x8f8e8d),
            lv_color_hex(0x212121)
        );  
        lv_obj_t * skills = UI::create_button(
            auton_screen1,
            "Skills",
            245,
            10,
            215,
            180
        );
        UI::font(
            skills,
            &courier_new_24
        );
        UI::gradient(
            skills,
            lv_color_hex(0x8f8e8d),
            lv_color_hex(0x212121)
        );           


        // =========================
        // AUTON SCREEN(Alliance)
        // =========================
        lv_obj_t * back_auton2 = UI::create_button(
            auton_screen2,
            "BACK",
            10,
            200,
            460,
            40,
            auton_button
        );
        UI::background(
            auton_screen2,
            lv_color_hex(0x212121)
        );
        UI::gradient(
        back_auton2,
        lv_color_hex(0x8f8e8d),
        lv_color_hex(0x2121221)
        );
        UI::panel(
            auton_screen2,
            440,
            30,
            20,
            5
        );
        UI::image(
            auton_screen2,
            &field,
            250,
            40
            );
            lv_obj_t * alc = UI::create_button(
                auton_screen2,
                "",
                10,
                40,
                80,
                160,
                alc_change
            );
            UI::gradient(
                alc,
                lv_color_hex(0x8e0000),
                lv_color_hex(0x400000)
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
        lv_screen_load(auton_screen1);
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
    void Screens::show_auton2() {
        lv_screen_load(auton_screen2);
    }