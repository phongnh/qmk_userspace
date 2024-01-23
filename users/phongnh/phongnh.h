#pragma once

#include "quantum.h"
#include "version.h"

enum phongnh_custom_keycodes {
    VRSN = SAFE_RANGE,
    EPRM,
    KBD_RST,
    RGB_RST,
    PRT_SCR,
    CPY_SCR,
    PRT_WIN,
    CPY_WIN,
    PRT_SEL,
    CPY_SEL,
    NEW_SAFE_RANGE
};

bool is_mac(void);
bool macro_print_screen(bool pressed);
bool macro_copy_screen(bool pressed);
bool macro_print_window(bool pressed);
bool macro_copy_window(bool pressed);
bool macro_print_selection(bool pressed);
bool macro_copy_selection(bool pressed);
