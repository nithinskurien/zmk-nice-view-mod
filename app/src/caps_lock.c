#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);
#include <zmk/caps_lock.h>
#include <zmk/event_manager.h>
#include <zmk/events/caps_state_changed.h>
#include <zmk/events/keycode_state_changed.h>
#include <dt-bindings/zmk/hid_usage.h>
#include <stdbool.h>

bool last_state_of_caps_lock;

int keycode_event_listener(const zmk_event_t *eh) {
    const struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);
    if (ev) {
        if (!ev->state && ev->keycode == HID_USAGE_KEY_KEYBOARD_CAPS_LOCK) {
            last_state_of_caps_lock = !last_state_of_caps_lock;
            LOG_DBG("caps lock button pressed, state is %d", last_state_of_caps_lock);
            ZMK_EVENT_RAISE(new_zmk_caps_state_changed(
                (struct zmk_caps_state_changed){.state = last_state_of_caps_lock}));
        }
    }
    return 0;
}

bool zmk_caps_lock_state() { return last_state_of_caps_lock; }

ZMK_LISTENER(caps_lock, keycode_event_listener);
ZMK_SUBSCRIPTION(caps_lock, zmk_keycode_state_changed);

//