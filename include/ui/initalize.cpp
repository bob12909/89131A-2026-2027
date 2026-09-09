#include "liblvgl/display/lv_display.h"
#include "liblvgl/lv_init.h"
#include "liblvgl/misc/lv_color.h"
#include "liblvgl/misc/lv_types.h"
#include "liblvgl/themes/default/lv_theme_default.h"
#include "liblvgl/tick/lv_tick.h"
#include "themes.hpp"
#include "pros/colors.hpp"
#include "pros/rtos.hpp"
#include "pros/screen.hpp"
#include "ui/screens.hpp"
#include "ui/buttons.hpp"

void my_flush_cb(
    lv_display_t *disp,
    const lv_area_t *area,
    uint8_t *color_p
) {
    for (int y = area->y1; y <= area->y2; y++) {
        for (int x = area->x1; x <= area->x2; x++) {

            int width = area->x2 - area->x1 + 1;

            int index =
                (y - area->y1) * width +
                (x - area->x1);

            uint16_t color =
                ((uint16_t *)color_p)[index];

            pros::screen::set_pen(pros::Color(color));
            pros::screen::draw_pixel(x, y);
        }
    }

    lv_display_flush_ready(disp);
}
void lvgl_task_fn(void*) {
    while (true) {
        lv_timer_handler();
        pros::delay(5);
    }
}
void initializeGUI() {

    lv_init();

    lv_tick_set_cb(pros::millis);

    lv_display_t *display = lv_display_create(480, 240);

    static uint8_t buf1[480 * 240 / 10 * 2];

    lv_display_set_buffers(
        display,
        buf1,
        NULL,
        sizeof(buf1),
        LV_DISPLAY_RENDER_MODE_PARTIAL
    );

    lv_display_set_flush_cb(display, my_flush_cb);

    // Your GUI objects go below this point
}