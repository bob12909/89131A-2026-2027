#pragma once

#include "liblvgl/lvgl.h"

namespace Themes {

    // Keep track of all the themes your UI supports
    enum class ID {
        VEX,
        DARK,
        LIGHT,
        CYBER
    };

    // Theme objects
    inline lv_theme_t* vex = nullptr;
    inline lv_theme_t* dark = nullptr;
    inline lv_theme_t* light = nullptr;
    inline lv_theme_t* cyber = nullptr;


    // Initialize all themes
    inline void init(lv_display_t* display) {

        vex = lv_theme_default_init(
            display,
            lv_color_hex(0x8CC63F),
            lv_color_hex(0x6FA52F),
            true,
            &lv_font_montserrat_20
        );

        dark = lv_theme_default_init(
            display,
            lv_color_hex(0x444444),
            lv_color_hex(0x222222),
            true,
            &lv_font_montserrat_20
        );

        light = lv_theme_default_init(
            display,
            lv_color_hex(0xFFFFFF),
            lv_color_hex(0xDDDDDD),
            false,
            &lv_font_montserrat_20
        );

        cyber = lv_theme_default_init(
            display,
            lv_color_hex(0x00FFFF),
            lv_color_hex(0xFF00FF),
            true,
            &lv_font_montserrat_20
        );
    }


    // Get a theme by ID
    inline lv_theme_t* get(ID id) {

        switch (id) {

            case ID::VEX:
                return vex;

            case ID::DARK:
                return dark;

            case ID::LIGHT:
                return light;

            case ID::CYBER:
                return cyber;
        }

        return vex;
    }

}