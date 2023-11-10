#pragma once

#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zmk/event_manager.h>

struct zmk_caps_state_changed {
    bool state;
};

ZMK_EVENT_DECLARE(zmk_caps_state_changed);