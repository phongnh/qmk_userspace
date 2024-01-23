#include "phongnh.h"

extern keymap_config_t keymap_config;

bool is_mac() {
    return keymap_config.swap_lalt_lgui;
}

bool macro_print_screen(bool pressed) {
    if (is_mac()) {
        if (pressed) {
            register_mods(MOD_LGUI | MOD_LSFT);
            register_code(KC_3);
        } else {
            unregister_code(KC_3);
            unregister_mods(MOD_LGUI | MOD_LSFT);
        }
    } else {
        if (pressed) {
            register_code(KC_PSCR);
        } else {
            unregister_code(KC_PSCR);
        }
    }
    return false;
}

bool macro_copy_screen(bool pressed) {
    if (is_mac()) {
        if (pressed) {
            register_mods(MOD_LGUI | MOD_LSFT | MOD_LCTL);
            register_code(KC_3);
        } else {
            unregister_code(KC_3);
            unregister_mods(MOD_LGUI | MOD_LSFT | MOD_LCTL);
        }
    } else {
        if (pressed) {
            register_mods(MOD_LCTL);
            register_code(KC_PSCR);
        } else {
            unregister_code(KC_PSCR);
            unregister_mods(MOD_LCTL);
        }
    }
    return false;
}

bool macro_print_window(bool pressed) {
    if (is_mac()) {
        if (pressed) {
            register_mods(MOD_LGUI | MOD_LSFT);
            register_code(KC_4);
        } else {
            tap_code(KC_SPC);
            tap_code(KC_ENT);
            unregister_code(KC_4);
            unregister_mods(MOD_LGUI | MOD_LSFT);
        }
    } else {
        if (pressed) {
            register_mods(MOD_LALT);
            register_code(KC_PSCR);
        } else {
            unregister_code(KC_PSCR);
            unregister_mods(MOD_LALT);
        }
    }
    return false;
}

bool macro_copy_window(bool pressed) {
    if (is_mac()) {
        if (pressed) {
            register_mods(MOD_LGUI | MOD_LSFT | MOD_LCTL);
            register_code(KC_4);
        } else {
            tap_code(KC_SPC);
            tap_code(KC_ENT);
            unregister_code(KC_4);
            unregister_mods(MOD_LGUI | MOD_LSFT | MOD_LCTL);
        }
    } else {
        if (pressed) {
            register_mods(MOD_LALT | MOD_LCTL);
            register_code(KC_PSCR);
        } else {
            unregister_code(KC_PSCR);
            unregister_mods(MOD_LALT | MOD_LCTL);
        }
    }
    return false;
}

bool macro_print_selection(bool pressed) {
    if (is_mac()) {
        if (pressed) {
            register_mods(MOD_LGUI | MOD_LSFT);
            register_code(KC_4);
        } else {
            unregister_code(KC_4);
            unregister_mods(MOD_LGUI | MOD_LSFT);
        }
    } else {
        if (pressed) {
            register_mods(MOD_LSFT);
            register_code(KC_PSCR);
        } else {
            unregister_code(KC_PSCR);
            unregister_mods(MOD_LSFT);
        }
    }
    return false;
}

bool macro_copy_selection(bool pressed) {
    if (is_mac()) {
        if (pressed) {
            register_mods(MOD_LGUI | MOD_LSFT | MOD_LCTL);
            register_code(KC_4);
        } else {
            unregister_code(KC_4);
            unregister_mods(MOD_LGUI | MOD_LSFT | MOD_LCTL);
        }
    } else {
        if (pressed) {
            register_mods(MOD_LSFT | MOD_LCTL);
            register_code(KC_PSCR);
        } else {
            unregister_code(KC_PSCR);
            unregister_mods(MOD_LSFT | MOD_LCTL);
        }
    }
    return false;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t reset_timer;
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " - OS: ");
                if (is_mac()) {
                    SEND_STRING("macOS");
                } else {
                    SEND_STRING("Windows/Linux");
                }
            }
            return false;
            break;
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case KBD_RST:
            if (record->event.pressed) {
                reset_timer = timer_read();
            } else if (timer_elapsed(reset_timer) >= 500) {
                reset_keyboard();
            }
            return false;
            break;
        case RGB_RST:
#if defined(RGBLIGHT_ENABLE)
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
#elif defined(RGB_MATRIX_ENABLE)
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
#endif
            return false;
            break;
        case PRT_SCR:
            return macro_print_screen(record->event.pressed);
            break;
        case CPY_SCR:
            return macro_copy_screen(record->event.pressed);
            break;
        case PRT_WIN:
            return macro_print_window(record->event.pressed);
            break;
        case CPY_WIN:
            return macro_copy_window(record->event.pressed);
            break;
        case PRT_SEL:
            return macro_print_selection(record->event.pressed);
            break;
        case CPY_SEL:
            return macro_copy_selection(record->event.pressed);
            break;
    }
    return process_record_keymap(keycode, record);
}
