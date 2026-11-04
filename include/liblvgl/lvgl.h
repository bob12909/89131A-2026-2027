/**
 * @file lvgl.h
 * This file exists only to be compatible with Arduino's library structure
 */

#ifndef LVGL_SRC_H
#define LVGL_SRC_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_private.h"
#include "liblvgl/lv_init.h"

#include "liblvgl/stdlib/lv_mem.h"
#include "liblvgl/stdlib/lv_string.h"
#include "liblvgl/stdlib/lv_sprintf.h"

#include "liblvgl/misc/lv_log.h"
#include "liblvgl/misc/lv_timer.h"
#include "liblvgl/misc/lv_math.h"
#include "liblvgl/misc/lv_array.h"
#include "liblvgl/misc/lv_async.h"
#include "liblvgl/misc/lv_anim_timeline.h"
#include "liblvgl/misc/lv_profiler_builtin.h"
#include "liblvgl/misc/lv_rb.h"
#include "liblvgl/misc/lv_utils.h"

#include "liblvgl/tick/lv_tick.h"

#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_group.h"
#include "liblvgl/indev/lv_indev.h"
#include "liblvgl/core/lv_refr.h"
#include "liblvgl/display/lv_display.h"

#include "liblvgl/font/lv_font.h"
#include "liblvgl/font/lv_binfont_loader.h"
#include "liblvgl/font/lv_font_fmt_txt.h"

#include "liblvgl/widgets/animimage/lv_animimage.h"
#include "liblvgl/widgets/arc/lv_arc.h"
#include "liblvgl/widgets/bar/lv_bar.h"
#include "liblvgl/widgets/button/lv_button.h"
#include "liblvgl/widgets/buttonmatrix/lv_buttonmatrix.h"
#include "liblvgl/widgets/calendar/lv_calendar.h"
#include "liblvgl/widgets/canvas/lv_canvas.h"
#include "liblvgl/widgets/chart/lv_chart.h"
#include "liblvgl/widgets/checkbox/lv_checkbox.h"
#include "liblvgl/widgets/dropdown/lv_dropdown.h"
#include "liblvgl/widgets/image/lv_image.h"
#include "liblvgl/widgets/imagebutton/lv_imagebutton.h"
#include "liblvgl/widgets/keyboard/lv_keyboard.h"
#include "liblvgl/widgets/label/lv_label.h"
#include "liblvgl/widgets/led/lv_led.h"
#include "liblvgl/widgets/line/lv_line.h"
#include "liblvgl/widgets/list/lv_list.h"
#include "liblvgl/widgets/lottie/lv_lottie.h"
#include "liblvgl/widgets/menu/lv_menu.h"
#include "liblvgl/widgets/msgbox/lv_msgbox.h"
#include "liblvgl/widgets/roller/lv_roller.h"
#include "liblvgl/widgets/scale/lv_scale.h"
#include "liblvgl/widgets/slider/lv_slider.h"
#include "liblvgl/widgets/span/lv_span.h"
#include "liblvgl/widgets/spinbox/lv_spinbox.h"
#include "liblvgl/widgets/spinner/lv_spinner.h"
#include "liblvgl/widgets/switch/lv_switch.h"
#include "liblvgl/widgets/table/lv_table.h"
#include "liblvgl/widgets/tabview/lv_tabview.h"
#include "liblvgl/widgets/textarea/lv_textarea.h"
#include "liblvgl/widgets/tileview/lv_tileview.h"
#include "liblvgl/widgets/win/lv_win.h"

#include "liblvgl/others/snapshot/lv_snapshot.h"
#include "liblvgl/others/sysmon/lv_sysmon.h"
#include "liblvgl/others/monkey/lv_monkey.h"
#include "liblvgl/others/gridnav/lv_gridnav.h"
#include "liblvgl/others/fragment/lv_fragment.h"
#include "liblvgl/others/imgfont/lv_imgfont.h"
#include "liblvgl/others/observer/lv_observer.h"
#include "liblvgl/others/ime/lv_ime_pinyin.h"
#include "liblvgl/others/file_explorer/lv_file_explorer.h"

#include "liblvgl/libs/barcode/lv_barcode.h"
#include "liblvgl/libs/bin_decoder/lv_bin_decoder.h"
#include "liblvgl/libs/bmp/lv_bmp.h"
#include "liblvgl/libs/rle/lv_rle.h"
#include "liblvgl/libs/fsdrv/lv_fsdrv.h"
#include "liblvgl/libs/lodepng/lv_lodepng.h"
#include "liblvgl/libs/libpng/lv_libpng.h"
#include "liblvgl/libs/gif/lv_gif.h"
#include "liblvgl/libs/qrcode/lv_qrcode.h"
#include "liblvgl/libs/tjpgd/lv_tjpgd.h"
#include "liblvgl/libs/libjpeg_turbo/lv_libjpeg_turbo.h"
#include "liblvgl/libs/freetype/lv_freetype.h"
#include "liblvgl/libs/rlottie/lv_rlottie.h"
#include "liblvgl/libs/ffmpeg/lv_ffmpeg.h"
#include "liblvgl/libs/tiny_ttf/lv_tiny_ttf.h"

#include "liblvgl/layouts/lv_layout.h"

#include "liblvgl/draw/lv_draw.h"
#include "liblvgl/draw/lv_draw_buf.h"
#include "liblvgl/draw/lv_draw_vector.h"
#include "liblvgl/draw/sw/lv_draw_sw.h"

#include "liblvgl/themes/lv_theme.h"

#include "liblvgl/drivers/lv_drivers.h"

// #include "liblvgl/lv_api_map_v8.h"
#include "liblvgl/lv_api_map_v9_0.h"
#include "liblvgl/lv_api_map_v9_1.h"

#if LV_USE_PRIVATE_API
#include "liblvgl/lvgl_private.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* LVGL_SRC_H */
