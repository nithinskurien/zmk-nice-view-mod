#include <stdint.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include "anim_widget.h"

const void **images;

LV_IMG_DECLARE(anim_inf_0);
LV_IMG_DECLARE(anim_inf_1);
LV_IMG_DECLARE(anim_inf_2);
LV_IMG_DECLARE(anim_inf_3);
LV_IMG_DECLARE(anim_inf_4);
LV_IMG_DECLARE(anim_inf_5);
LV_IMG_DECLARE(anim_inf_6);
LV_IMG_DECLARE(anim_inf_7);
LV_IMG_DECLARE(anim_inf_8);
LV_IMG_DECLARE(anim_inf_9);
LV_IMG_DECLARE(anim_inf_10);
LV_IMG_DECLARE(anim_inf_11);
LV_IMG_DECLARE(anim_inf_12);
LV_IMG_DECLARE(anim_inf_13);
LV_IMG_DECLARE(anim_inf_14);
LV_IMG_DECLARE(anim_inf_15);
LV_IMG_DECLARE(anim_inf_16);
LV_IMG_DECLARE(anim_inf_17);
LV_IMG_DECLARE(anim_inf_18);
LV_IMG_DECLARE(anim_inf_19);
LV_IMG_DECLARE(anim_inf_20);
LV_IMG_DECLARE(anim_inf_21);
LV_IMG_DECLARE(anim_inf_22);
LV_IMG_DECLARE(anim_inf_23);
LV_IMG_DECLARE(anim_inf_24);
LV_IMG_DECLARE(anim_inf_25);
LV_IMG_DECLARE(anim_inf_26);
LV_IMG_DECLARE(anim_inf_27);
LV_IMG_DECLARE(anim_inf_28);
LV_IMG_DECLARE(anim_inf_29);
LV_IMG_DECLARE(anim_inf_30);
LV_IMG_DECLARE(anim_inf_31);
LV_IMG_DECLARE(anim_inf_32);

const void *anim_images[] = {
    &anim_inf_0,  &anim_inf_1,  &anim_inf_2,  &anim_inf_3,  &anim_inf_4,  &anim_inf_5,
    &anim_inf_6,  &anim_inf_7,  &anim_inf_8,  &anim_inf_9,  &anim_inf_10, &anim_inf_11,
    &anim_inf_12, &anim_inf_13, &anim_inf_14, &anim_inf_15, &anim_inf_16, &anim_inf_17,
    &anim_inf_18, &anim_inf_19, &anim_inf_20, &anim_inf_21, &anim_inf_22, &anim_inf_23,
    &anim_inf_24, &anim_inf_25, &anim_inf_26, &anim_inf_27, &anim_inf_28, &anim_inf_29,
    &anim_inf_30, &anim_inf_31, &anim_inf_32,
};

void set_img_src(void *var, int val) {
    lv_obj_t *img = (lv_obj_t *)var;
    lv_img_set_src(img, images[val]);
}

void update_anim_widget(struct zmk_widget_anim *widget) {
    LOG_DBG("Set source to idle images!");
    lv_anim_init(&widget->anim);
    lv_anim_set_var(&widget->anim, widget->canvas);
    lv_anim_set_time(&widget->anim, 3000);
    lv_anim_set_values(&widget->anim, 0, 32);
    lv_anim_set_exec_cb(&widget->anim, set_img_src);
    lv_anim_set_repeat_count(&widget->anim, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&widget->anim, 100);
    images = anim_images;
    lv_anim_start(&widget->anim);
}

int zmk_widget_anim_init(struct zmk_widget_anim *widget, lv_obj_t *canvas) {
    widget->canvas = canvas;
    update_anim_widget(widget);
    return 0;
}

lv_obj_t *zmk_widget_anim_obj(struct zmk_widget_anim *widget) { return widget->canvas; }