#pragma once

// Mouse Settings
#ifdef MOUSEKEY_INTERVAL
#undef MOUSEKEY_INTERVAL
#endif
#define MOUSEKEY_INTERVAL 20

#ifdef MOUSEKEY_DELAY
#undef MOUSEKEY_DELAY
#endif
#define MOUSEKEY_DELAY 0

#ifdef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_TIME_TO_MAX
#endif
#define MOUSEKEY_TIME_TO_MAX 5

#ifdef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_MAX_SPEED
#endif
#define MOUSEKEY_MAX_SPEED 3

#ifdef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_WHEEL_DELAY
#endif
#define MOUSEKEY_WHEEL_DELAY 0

#ifdef TAPPING_TOGGLE
#undef TAPPING_TOGGLE
#endif
#define TAPPING_TOGGLE 1

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 200

// Disable unused and unneeded features to reduce on firmware size
#ifdef LOCKING_SUPPORT_ENABLE
#undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#undef LOCKING_RESYNC_ENABLE
#endif

// QK_GESC
// Always send Escape if Alt is pressed
#define GRAVE_ESC_ALT_OVERRIDE
// Always send Escape if Control is pressed
#define GRAVE_ESC_CTRL_OVERRIDE
// Always send Escape if GUI is pressed
#define GRAVE_ESC_GUI_OVERRIDE
// Always send Escape if Shift is pressed
// #define GRAVE_ESC_SHIFT_OVERRIDE

// Caps Word configuration
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000 // Automatically turn off after x milliseconds of idle. 0 to never timeout.
