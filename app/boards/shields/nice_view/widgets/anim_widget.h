#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct zmk_widget_anim {
    sys_snode_t node;
    lv_anim_t anim;
    lv_obj_t *canvas;
    lv_color_t *cbuf;
};

int zmk_widget_anim_init(struct zmk_widget_anim *widget, lv_obj_t *canvas);
lv_obj_t *zmk_widget_anim_obj(struct zmk_widget_anim *widget);