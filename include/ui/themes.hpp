#pragma once

#include "liblvgl/lvgl.h"

namespace Themes {

    enum class ID {
        DARK,
        SHY,
        KENZY,
        BRAYDEN
    };

    struct Colors {
        lv_color_t background;
        lv_color_t panel;

        lv_color_t primary;
        lv_color_t secondary;

        lv_color_t text;
        lv_color_t text_secondary;

        lv_color_t accent;
    };


    inline const Colors dark = {
        .background     = lv_color_hex(0x080808),
        .panel          = lv_color_hex(0x151515),
        .primary        = lv_color_hex(0x444444),
        .secondary      = lv_color_hex(0x666666),
        .text           = lv_color_hex(0xFFFFFF),
        .text_secondary = lv_color_hex(0x888888),
        .accent         = lv_color_hex(0xAAAAAA)
    };

    inline const Colors shy = {
        .background     = lv_color_hex(0x101010),
        .panel          = lv_color_hex(0x202020),
        .primary        = lv_color_hex(0x8CC63F),
        .secondary      = lv_color_hex(0x6FA52F),
        .text           = lv_color_hex(0xFFFFFF),
        .text_secondary = lv_color_hex(0xAAAAAA),
        .accent         = lv_color_hex(0x8CC63F)
    };

    inline const Colors kenzy = {
        .background     = lv_color_hex(0x3a3a3b),
        .panel          = lv_color_hex(0x51495e),
        .primary        = lv_color_hex(0x2e1854),
        .secondary      = lv_color_hex(0x6FA52F),
        .text           = lv_color_hex(0xFFFFFF),
        .text_secondary = lv_color_hex(0xAAAAAA),
        .accent         = lv_color_hex(0x8CC63F)
    };
    inline const Colors brayden = {
        .background     = lv_color_hex(0x0a0a0f),
        .panel          = lv_color_hex(0x2a0b52),
        .primary        = lv_color_hex(0x6a1b9a),
        .secondary      = lv_color_hex(0x2a0b52),
        .text           = lv_color_hex(0xFFFFFF),
        .text_secondary = lv_color_hex(0xAAAAAA),
        .accent         = lv_color_hex(0xc084fc)
    };

    inline const Colors* current = &dark;


    inline const Colors& get(ID id) {

        switch (id) {

            case ID::DARK:
                return dark;
            case ID::SHY:
                return shy;
            case ID::KENZY:
                return kenzy;
            case ID::BRAYDEN:
                return brayden;
        }

        return dark;
    }


    inline void set(ID id) {
        current = &get(id);
    }

}