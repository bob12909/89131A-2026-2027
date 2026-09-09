#pragma once

#include "liblvgl/lvgl.h"
#include "themes.hpp"

namespace UI {

    inline lv_obj_t* create_button(
        lv_obj_t* parent,
        const char* text,
        int x,
        int y,
        int width,
        int height,
        lv_event_cb_t callback = nullptr
    ) {

        lv_obj_t* button = lv_button_create(parent);

        lv_obj_set_size(button, width, height);
        lv_obj_set_pos(button, x, y);

        lv_obj_set_style_bg_color(
            button,
            Themes::current->panel,
            0
        );

        lv_obj_set_style_border_color(
            button,
            Themes::current->primary,
            0
        );

        lv_obj_set_style_border_width(
            button,
            2,
            0
        );

        lv_obj_set_style_radius(
            button,
            8,
            0
        );

        lv_obj_t* label = lv_label_create(button);

        lv_label_set_text(label, text);

        lv_obj_center(label);

        lv_obj_set_style_text_color(
            label,
            Themes::current->text,
            0
        );

        // Add callback if one was provided
        if (callback != nullptr) {
            lv_obj_add_event_cb(
                button,
                callback,
                LV_EVENT_CLICKED,
                nullptr
            );
        }

        return button;
    }

}