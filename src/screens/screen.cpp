    #include "ui/screens.hpp"
    #include "ui/themes.hpp"
    #include "ui/buttons.hpp"
    #include "fonts.hpp"
    #include "imgs.hpp"
    #include <string>
    #include <list>
    int ID = 0;
    namespace {

        lv_obj_t* main_screen;
        lv_obj_t* auton_screen1;
        lv_obj_t* settings_screen;
        lv_obj_t* motors_screen;
        lv_obj_t* debug_screen;
        lv_obj_t * auton_screen2;
        lv_obj_t * al_screen;

    }

    // -------------------------
    // Button callbacks
    // -------------------------
    std::string auton_name = "";
    lv_color_t  disconected1 = lv_color_hex(0x8f8e8d);
    lv_color_t  disconected2 = lv_color_hex(0x212121);
    lv_color_t  ready1 = lv_color_hex(0x00ff00);
    lv_color_t  ready2 = lv_color_hex(0x002200);
    lv_color_t  med1 = lv_color_hex(0xf2c51f);
    lv_color_t  med2 = lv_color_hex(0xebcc5e);
    lv_color_t  burn1 = lv_color_hex(0x2f0000);
    lv_color_t  burn2 = lv_color_hex(0x220000);
    double auton_select = 0;
    lv_color_t  qc1 = lv_color_hex(0x8f8e8d);
    lv_color_t  qc2 = lv_color_hex(0x212121);
    lv_color_t  qc3 = lv_color_hex(0x8f8e8d);
    lv_color_t  qc4 = lv_color_hex(0x212121);
    lv_color_t  qc5 = lv_color_hex(0x8f8e8d);
    lv_color_t  qc6 = lv_color_hex(0x212121);
    double als = 1;
    lv_color_t  c1 = lv_color_hex(0x8e0000);
    lv_color_t  c2 = lv_color_hex(0x400000);
    double alcc = 0;
    std::string name = "kenzy";
    double name_c = 0;
    std::string theme = "dark";
    std::string side = "red";
    void alc_change(lv_event_t* event){
        alcc += 1;
        if (alcc == 0)
        {
            auton_name = "Red Q1 selected";
            c1 = lv_color_hex(0x8e0000);
            c2 = lv_color_hex(0x400000);
            side = "red";
            auton_select = 1;
            qc1 = lv_color_hex(0x002e00);
            qc2 = lv_color_hex(0x022000);
            qc3 = lv_color_hex(0x8f8e8d);
            qc4 = lv_color_hex(0x212121);
            qc5 = lv_color_hex(0x8f8e8d);
            qc6 = lv_color_hex(0x212121);
        }
        else if (alcc == 1){
            auton_name = "Blue Q1 selected";
            c1 = lv_color_hex(0x00008e);
            c2 = lv_color_hex(0x000040);
            side = "blue";
            auton_select = 4;
            qc1 = lv_color_hex(0x002e00);
            qc2 = lv_color_hex(0x022000);
            qc3 = lv_color_hex(0x8f8e8d);
            qc4 = lv_color_hex(0x212121);
            qc5 = lv_color_hex(0x8f8e8d);
            qc6 = lv_color_hex(0x212121);
        }
        else if (alcc == 2) {
            auton_name = "Red Q1 selected";
            alcc = 0;
            c1 = lv_color_hex(0x8e0000);
            c2 = lv_color_hex(0x400000);
            side = "red";
            auton_select = 1;
            qc1 = lv_color_hex(0x002e00);
            qc2 = lv_color_hex(0x022000);
            qc3 = lv_color_hex(0x8f8e8d);
            qc4 = lv_color_hex(0x212121);
            qc5 = lv_color_hex(0x8f8e8d);
            qc6 = lv_color_hex(0x212121);
        }
        Screens::init();
        Screens::show_auton2();
    }
    void alss(int what_q, lv_event_t *event);
    void als_callback(lv_event_t *event) {
    int what_q = (int)(intptr_t)lv_event_get_user_data(event);
    alss(what_q, event);
    }
    void alss(int what_q, lv_event_t * event){
        if (side == "red"){
        if (what_q == 1){
            auton_select = 1;
            qc1 = lv_color_hex(0x002e00);
            qc2 = lv_color_hex(0x022000);
            qc3 = lv_color_hex(0x8f8e8d);
            qc4 = lv_color_hex(0x212121);
            qc5 = lv_color_hex(0x8f8e8d);
            qc6 = lv_color_hex(0x212121);
            auton_name = "Red Q1 selected";
        }
        else if (what_q == 2){
            auton_select = 2;
            qc1 = lv_color_hex(0x8f8e8d);
            qc2 = lv_color_hex(0x212121);
            qc3 = lv_color_hex(0x002e00);
            qc4 = lv_color_hex(0x022000);
            qc5 = lv_color_hex(0x8f8e8d);
            qc6 = lv_color_hex(0x212121);
            auton_name = "Red Q2 selected";
        }
        else if (what_q == 3){
            auton_select = 3;
            qc1 = lv_color_hex(0x8f8e8d);
            qc2 = lv_color_hex(0x212121);
            qc3 = lv_color_hex(0x8f8e8d);
            qc4 = lv_color_hex(0x212121);
            qc5 = lv_color_hex(0x002e00);
            qc6 = lv_color_hex(0x022000);
            auton_name = "Red Solo AWP selected";
        }
    }
    if (side == "blue"){
        if (what_q == 1){
            auton_select = 4;
            qc1 = lv_color_hex(0x002e00);
            qc2 = lv_color_hex(0x022000);
            qc3 = lv_color_hex(0x8f8e8d);
            qc4 = lv_color_hex(0x212121);
            qc5 = lv_color_hex(0x8f8e8d);
            qc6 = lv_color_hex(0x212121);
            auton_name = "Blue Q1 selected";
            }
        else if (what_q == 2){
            auton_select = 5;
            qc1 = lv_color_hex(0x8f8e8d);
            qc2 = lv_color_hex(0x212121);
            qc3 = lv_color_hex(0x002e00);
            qc4 = lv_color_hex(0x022000);
            qc5 = lv_color_hex(0x8f8e8d);
            qc6 = lv_color_hex(0x212121);
            auton_name = "Blue Q2 selected";
            }
        else if (what_q == 3){
            auton_select = 6;
            qc1 = lv_color_hex(0x8f8e8d);
            qc2 = lv_color_hex(0x212121);
            qc3 = lv_color_hex(0x8f8e8d);
            qc4 = lv_color_hex(0x212121);
            qc5 = lv_color_hex(0x002e00);
            qc6 = lv_color_hex(0x022000);
            auton_name = "Blue Solo AWP selected";
            }
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
    void drive_button(lv_event_t * event){
        Screens::show_drive();
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
        al_screen = lv_obj_create(NULL);


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
        UI::label(
            auton_screen2,
            "Alliance",
            190,
            12, 
            &courier_new_24);
        UI::image_button(
            auton_screen2,
            &field,
            155,
            155,
            250,
            40,
            drive_button
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
                c1,
                c2
            );
            lv_obj_t * q1 = UI::create_button(
                auton_screen2,
                "Q1",
                95,
                40,
                90,
                50,
                als_callback,
                1
            );
            UI::gradient(
                q1,
                qc1,
                qc2
            );
            lv_obj_t * q2 = UI::create_button(
                auton_screen2,
                "Q2",
                95,
                95,
                90,
                50,
                als_callback,
                2
            );
            UI::gradient(
                q2,
                qc3,
                qc4
            );

            lv_obj_t * sawp = UI::create_button(
                auton_screen2,
                "Solo AWP",
                95,
                150,
                90,
                50,
                als_callback,
                3
            );
            UI::gradient(
                sawp,
                qc5,
                qc6
            );


        // =========================
        // AUTON SELECTED SCREEN
        // =========================
            lv_obj_t * back3 = UI::create_button(
            al_screen,
            "BACK",
            10,
            200,
            460,
            40,
            auton_button
        );
        UI::background(
            al_screen,
            lv_color_hex(0x212121)
        );
        UI::gradient(
        back3,
        lv_color_hex(0x8f8e8d),
        lv_color_hex(0x2121221)
        );
        UI::panel(
            al_screen,
            440,
            30,
            20,
            5
        );
        UI::label(
            al_screen,
            auton_name.c_str(),
            150,
            12, 
            &courier_new_24
        );
        UI::image(
            al_screen
        ,&field,
        240,
        40
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
        lv_obj_t * back_motor = UI::create_button(
            motors_screen,
            "BACK",
            10,
            200,
            460,
            40,
            main_button
        );
        UI::background(
            motors_screen,
            lv_color_hex(0x212121)
        );
        UI::gradient(
        back_motor,
        lv_color_hex(0x8f8e8d),
        lv_color_hex(0x2121221)
        );
        lv_obj_t * motor = UI::panel(
            motors_screen,
            440,
            30,
            20,
            5
        );
        UI::label(
            motors_screen,
            "motors",
            190,
            11,
            &courier_new_24
        );
        UI::gradient(
            motor,
            lv_color_hex(0x8f8e8d),
            lv_color_hex(0x2121221)
        );
        lv_obj_t * L1 = UI::panel(motors_screen,50,50,20,40);
        lv_obj_t * L2 = UI::panel(motors_screen,50,50,20,95);
        lv_obj_t * L3 = UI::panel(motors_screen,50,50,20,150);
        lv_obj_t * R1 = UI::panel(motors_screen,50,50,75,40);
        lv_obj_t * R2 = UI::panel(motors_screen,50,50,75,95);
        lv_obj_t * R3 = UI::panel(motors_screen,50,50,75,150);

        lv_obj_t * lift_L1 = UI::panel(motors_screen,50,50,180,40);
        lv_obj_t * lift_R1 = UI::panel(motors_screen,50,50,235,40);

        lv_obj_t * roller1 = UI::panel(motors_screen,50,50,355,40);
        lv_obj_t * roler2 = UI::panel(motors_screen,50,50,410,40);
        
        
        
        
    

    // -------------------------
    // debug
    // -------------------------
     



    }
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
    void Screens::show_drive() {
        lv_screen_load(al_screen);
    }