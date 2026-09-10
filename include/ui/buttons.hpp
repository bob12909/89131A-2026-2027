#pragma once
#include "liblvgl/lvgl.h"
#include "ui/themes.hpp"

namespace UI {

    // ============================================================
    // Theme
    // ============================================================

    inline const Themes::Colors& theme() {
        return *Themes::current;
    }


    // ============================================================
    // Basic styling
    // ============================================================

    inline void background(
        lv_obj_t* obj,
        lv_color_t color
    ) {
        lv_obj_set_style_bg_color(obj, color, 0);
        lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    }


    inline void text_color(
        lv_obj_t* obj,
        lv_color_t color
    ) {
        lv_obj_set_style_text_color(obj, color, 0);
    }


    inline void radius(
        lv_obj_t* obj,
        int32_t value
    ) {
        lv_obj_set_style_radius(obj, value, 0);
    }


    inline void size(
        lv_obj_t* obj,
        int32_t width,
        int32_t height
    ) {
        lv_obj_set_size(obj, width, height);
    }


    inline void position(
        lv_obj_t* obj,
        int32_t x,
        int32_t y
    ) {
        lv_obj_set_pos(obj, x, y);
    }


    // ============================================================
    // Screen
    // ============================================================

    inline lv_obj_t* screen(
        lv_color_t color
    ) {
        lv_obj_t* obj = lv_obj_create(NULL);

        background(obj, color);

        return obj;
    }


    inline lv_obj_t* screen() {
        return screen(theme().background);
    }


    // ============================================================
    // Panel
    // ============================================================

    inline lv_obj_t* panel(
        lv_obj_t* parent,
        int32_t width,
        int32_t height,
        int32_t x,
        int32_t y
    ) {
        lv_obj_t* obj = lv_obj_create(parent);

        size(obj, width, height);
        lv_obj_set_pos( obj, x, y);

        background(obj, theme().panel);

        radius(obj, 12);

        return obj;
    }


    // ============================================================
    // Label / Text
    // ============================================================

    inline lv_obj_t* label(
    lv_obj_t* parent,
    const char* text,
    int32_t x,
    int32_t y,
    const lv_font_t* font = &lv_font_montserrat_16
) {
    lv_obj_t* obj = lv_label_create(parent);

    lv_label_set_text(obj, text);

    lv_obj_set_pos(obj, x, y);

    lv_obj_set_style_text_color( obj, theme().text, 0 );

    lv_obj_set_style_text_font( obj, font, 0);

    return obj;
}


    inline lv_obj_t* secondary_label(
        lv_obj_t* parent,
        const char* text
    ) {
        lv_obj_t* obj = lv_label_create(parent);

        lv_label_set_text(obj, text);

        text_color(obj, theme().text_secondary);

        return obj;
    }


    // ============================================================
// Button
// ============================================================

inline lv_obj_t* create_button(
    lv_obj_t* parent,
    const char* text,
    int32_t x,
    int32_t y,
    int32_t width,
    int32_t height,
    lv_event_cb_t callback = nullptr,
    void* user_data = nullptr
) {
    lv_obj_t* btn = lv_button_create(parent);

    lv_obj_set_pos(btn, x, y);
    lv_obj_set_size(btn, width, height);

    lv_obj_set_style_bg_color(
        btn,
        theme().primary,
        0
    );

    lv_obj_set_style_bg_opa(
        btn,
        LV_OPA_COVER,
        0
    );

    lv_obj_set_style_radius(
        btn,
        10,
        0
    );

    // Pressed state
    lv_obj_set_style_bg_color(
        btn,
        theme().accent,
        LV_STATE_PRESSED
    );

    // Button text
    lv_obj_t* label_obj = lv_label_create(btn);

    lv_label_set_text(
        label_obj,
        text
    );

    lv_obj_set_style_text_color(
        label_obj,
        theme().text,
        0
    );

    lv_obj_center(label_obj);

    // Click callback
    if (callback != nullptr) {
        lv_obj_add_event_cb(
            btn,
            callback,
            LV_EVENT_CLICKED,
            user_data
        );
    }

    return btn;
}


    // ============================================================
    // Image
    // ============================================================

    inline lv_obj_t* image(
        lv_obj_t* parent,
        const void* source
    ) {
        lv_obj_t* img = lv_image_create(parent);

        lv_image_set_src(
            img,
            source
        );

        return img;
    }


    // ============================================================
    // Image + Button
    // ============================================================

    inline lv_obj_t* image_button(
        lv_obj_t* parent,
        const void* source,
        int32_t width = 80,
        int32_t height = 80
    ) {
        lv_obj_t* btn = lv_button_create(parent);

        size(btn, width, height);

        lv_obj_set_style_bg_color(
            btn,
            theme().primary,
            0
        );

        lv_obj_set_style_bg_color(
            btn,
            theme().accent,
            LV_STATE_PRESSED
        );

        radius(btn, 10);


        lv_obj_t* img = lv_image_create(btn);

        lv_image_set_src(
            img,
            source
        );

        lv_obj_center(img);

        return btn;
    }


    // ============================================================
    // Button callback
    // ============================================================

    inline void on_click(
        lv_obj_t* obj,
        lv_event_cb_t callback,
        void* user_data = nullptr
    ) {
        lv_obj_add_event_cb(
            obj,
            callback,
            LV_EVENT_CLICKED,
            user_data
        );
    }

}