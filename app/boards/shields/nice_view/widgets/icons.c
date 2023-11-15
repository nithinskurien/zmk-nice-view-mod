#include <lvgl.h>

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_DISPLAY_PROFILE
#define LV_ATTRIBUTE_IMG_DISPLAY_PROFILE
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DISPLAY_PROFILE uint8_t
    display_profile_map[] = {
#if CONFIG_NICE_VIEW_WIDGET_INVERTED
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/
#else
        0x00, 0x00, 0x00, 0xff, /*Color of index 0*/
        0xff, 0xff, 0xff, 0xff, /*Color of index 1*/
#endif /*Color of index 1*/

        0x08, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0xcf, 0x80, 0xef, 0xc0, 0x7f, 0xc0,
        0x3f, 0x80, 0x1f, 0x00, 0x0e, 0x00, 0x1f, 0x00, 0x3f, 0x80, 0x7f, 0xc0,
        0xef, 0xc0, 0x4f, 0x80, 0x0e, 0x00, 0x0c, 0x00, 0x08, 0x00,
};

const lv_img_dsc_t display_profile = {
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 10,
    .header.h = 17,
    .data_size = 42,
    .data = display_profile_map,
};

#ifndef LV_ATTRIBUTE_IMG_DISPLAY_CAPS
#define LV_ATTRIBUTE_IMG_DISPLAY_CAPS
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DISPLAY_CAPS uint8_t
    display_caps_map[] = {
#if CONFIG_NICE_VIEW_WIDGET_INVERTED
        0xff, 0xff, 0xff, 0xff, /*Color of index 0*/
        0x00, 0x00, 0x00, 0xff, /*Color of index 1*/
#else
        0x00, 0x00, 0x00, 0xff, /*Color of index 0*/
        0xff, 0xff, 0xff, 0xff, /*Color of index 1*/
#endif /*Color of index 1*/

        0x80, 0x02, 0x03, 0x80, 0x07, 0x80, 0x0f, 0xc0, 0x1f, 0xe0, 0x3f,
        0xf0, 0x3f, 0xf8, 0x7f, 0xfc, 0x0f, 0xe0, 0x0f, 0xe0, 0x0f, 0xe0,
        0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x8a, 0xa2,
};

const lv_img_dsc_t display_caps = {
    .header.cf = LV_IMG_CF_INDEXED_1BIT,
    .header.always_zero = 0,
    .header.reserved = 0,
    .header.w = 15,
    .header.h = 16,
    .data_size = 40,
    .data = display_caps_map,
};