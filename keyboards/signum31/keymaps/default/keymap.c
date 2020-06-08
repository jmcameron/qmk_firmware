#include QMK_KEYBOARD_H


enum layers {
  NORMAL_LAYER = 0,
  FN_LAYER     = 1
//  MEDIA_LAYER  = 2
};


#define FUNC1 MO(FN_LAYER)

#define LAYER0 TO(NORMAL_LAYER)
#define LAYER1 TO(FN_LAYER)

// #define LAYER2 TO(MEDIA_LAYER)

#define FN_CAPS LT(FN_LAYER, KC_CAPS)

#define CTL_LBRC LCTL_T(KC_LBRC)
#define CTL_RBRC RCTL_T(KC_RBRC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [NORMAL_LAYER] = LAYOUT_ortho_5x12(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
    FN_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
    KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSPC,
    CTL_LBRC, KC_LGUI, KC_LALT, FUNC1,   KC_SPC,  KC_DEL,    KC_ENT,  KC_SPC,  KC_BSPC, FUNC1,   KC_RALT,  CTL_RBRC
  ),
  [FN_LAYER] = LAYOUT_ortho_5x12(
    KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_BSPC,
    _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_PSCR,  _______,
    _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,  _______,
    _______,  _______, _______, KC_CALC, _______, _______,   _______, KC_MUTE, _______, _______, _______,  _______,
    _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_PSCR,  _______
  ),
};


layer_state_t layer_state_set_user(layer_state_t state)
{
    // ??? turn_off_leds();

    switch (biton32(state))
    {
    case NORMAL_LAYER:
	break;

    case FN_LAYER:
	// ??? turn_on_led(RED_LED);
	break;

// ???     case MEDIA_LAYER:
// ??? 	// ??? turn_on_led(BLUE_LED);
// ??? 	break;
// ???     }
    }

    return state;
}
