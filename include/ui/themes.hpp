#pragma once

#include "imgs.hpp"
#include "liblvgl/lvgl.h"

namespace Themes {
    //where i set the ID of each theme
    enum class ID {
        AVHS,
        MC,
        DSA,
        Dog
    };
    // this is where i declare all of the colors and backgrounds 
    struct Colours {
        const lv_image_dsc_t* background;
        int32_t bgx = 0;
        int32_t bgy = 0;
        lv_color_t bc1;
        lv_color_t bc2;

        lv_color_t panel = lv_color_hex(0x2a0b52);

        lv_color_t primary = lv_color_hex(0x6a1b9a);
        lv_color_t secondary= lv_color_hex(0x2a0b52);

        lv_color_t text= lv_color_hex(0xFFFFFF);
        lv_color_t text_secondary= lv_color_hex(0xAAAAAA);

        lv_color_t accent= lv_color_hex(0xc084fc);
    };

    //this is where I set the colors for our arbor view high school theme
    inline const Colours AVHS = {
        .background   = &bg1,
        .bgx          = 0,
        .bgy          = 0,
        .bc1          = lv_color_hex(0x8f8e8d),
        .bc2          = lv_color_hex(0xff0000)
        
    };
    //this is our mechanical bulls color theme (the MC part of the name is a mispelling of MB for mechanical bulls)
    inline const Colours MC = {
        .background   = &mb,
        .bgx          = 0,
        .bgy          = 0,
        .bc1          = lv_color_hex(0x111111),
        .bc2          = lv_color_hex(0xfe3131)
    };
    //this is our DSA color theme (DSA is a alliance of teams in nevada that we are a part of)
    inline const Colours DSA = {
        .background   = &dsa,
        .bgx          = 0,
        .bgy          = 0,
        .bc1          = lv_color_hex(0x8e8f8d),
        .bc2          = lv_color_hex(0x877329)
    };
    // this is our dog theme that we made for fun (it has dogs)
    inline const Colours Dog = {
        .background   = &Dogs,
        .bgx          = 0,
        .bgy          = 0,
        .bc1          = lv_color_hex(0XFFFFFF),
        .bc2          = lv_color_hex(0x827858)
    };

    inline const Colours* current = &AVHS;


    inline const Colours& get(ID id) {
        // this is where we check for which ID is being called for
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