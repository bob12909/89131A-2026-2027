#pragma once

#include "liblvgl/lvgl.h"

namespace Themes {

    enum class ID {
        AVHS,
        MC,
        DSA,
        Dog
    };

    struct Colours {
        lv_color_t background;
        lv_color_t bc1;
        lv_color_t bc2;

        lv_color_t panel = lv_color_hex(0x2a0b52);

        lv_color_t primary = lv_color_hex(0x6a1b9a);
        lv_color_t secondary= lv_color_hex(0x2a0b52);

        lv_color_t text= lv_color_hex(0xFFFFFF);
        lv_color_t text_secondary= lv_color_hex(0xAAAAAA);

        lv_color_t accent= lv_color_hex(0xc084fc);
    };


    inline const Colours AVHS = {
        .background   = lv_color_hex(0x080808),
        .bc1          = lv_color_hex(0x151515),
        .bc2          = lv_color_hex(0x000000)
    };

    inline const Colours MC = {
        .background   = lv_color_hex(0x101010),
        .bc1          = lv_color_hex(0x202020),
        .bc2          = lv_color_hex(0x000000)
    };

    inline const Colours DSA = {
        .background   = lv_color_hex(0x3a3a3b),
        .bc1          = lv_color_hex(0x8e8f8d),
        .bc2          = lv_color_hex(0x877329)
    };
    inline const Colours Dog = {
        .background   = lv_color_hex(0x0a0a0f),
        .bc1          = lv_color_hex(0x2a0b52),
        .bc2          = lv_color_hex(0x000000)
    };

    inline const Colours* current = &AVHS;


    inline const Colours& get(ID id) {

        switch (id) {
            case ID::AVHS:
                return AVHS;
            case ID::MC:
                return MC;
            case ID::DSA:
                return DSA;
            case ID::Dog:
                return Dog;
        }

        return AVHS;
    }


    inline void set(ID id) {
        current = &get(id);
    }

}