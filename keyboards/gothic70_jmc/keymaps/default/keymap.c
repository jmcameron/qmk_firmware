
#include QMK_KEYBOARD_H

// Define layers
enum layers {
  NORMAL_LAYER = 0,
  FN1_LAYER    = 1,
  FN2_LAYER    = 2
};
#define FN_CAPS LT(1, KC_CAPS)
#define FN1 MO(FN1_LAYER)
#define FN2 MO(FN2_LAYER)

// Tap Dance Declarations
enum {
    TD_SCAPS = 0
};

#define SCAPS_LG TD(TD_SCAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [NORMAL_LAYER] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,    KC_BSPC,         KC_GRV,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,         KC_CIRC,  \
    FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_DEL, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     FN2,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,             KC_UP,                  \
    KC_LCTL, KC_LGUI,    KC_LALT,    KC_BSPC,    FN1,                   KC_SPC,           KC_RALT,   KC_RCTL,               KC_LEFT, KC_DOWN, KC_RGHT        \
  ),

  [FN1_LAYER] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,                   _______, \
    _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______,                            KC_INS, \
    _______, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, KC_MUTE, _______, _______, _______, _______, _______,             KC_PGUP,                \
    _______, _______,    _______,    KC_DEL,     _______,              _______,          _______,          _______,         KC_HOME, KC_PGDN, KC_END         \
  ),

  [FN2_LAYER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_VOLU, \
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_VOLD, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            KC_MSEL, \
    _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, _______,             KC_MSTP,                \
    _______, _______,    _______,     _______,   _______,              _______,          _______,          _______,         KC_MPRV, KC_MPLY, KC_MNXT        \
  )
};

void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(F7);
  writePinLow(F7);
  // set NumLock LED to output and low
  setPinOutput(F6);
  writePinLow(F6);
  // set ScrollLock LED to output and low
  setPinOutput(F5);
  writePinLow(F5);
}

void matrix_scan_user(void) {

}


uint32_t layer_state_set_user(uint32_t state)
{
    if (state & (1<<1)) {
    writePinHigh(F5);
    } else if (state & (1<<2)) {
        writePinLow(F5);
        writePinHigh(F6);
    } else if (state & (1<<3)) {
        writePinHigh(F5);
        writePinHigh(F6);
    } else {
        writePinLow(F5);
        writePinLow(F6);
    }
    return state;
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(F7);
    } else {
        writePinLow(F7);
    }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // double tap for caps
    [TD_SCAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    
};
