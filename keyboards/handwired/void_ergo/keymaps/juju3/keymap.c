#include QMK_KEYBOARD_H

enum layer_names {
  _WIN,
  _MAC,
  _NUM,
  _SYM
};

enum planck_keycodes {
  NUM = SAFE_RANGE,
  SYM
};

enum {
    TD_SNAKE = 0, // Start from 0 to ensure small index
};


// Global Mods
#define RESET QK_BOOTLOADER
#define _______ KC_TRNS
#define FINGER  KC_NO

// Main Layers
#define D_MAIN DF(_WIN)
#define D_MAC DF(_MAC)

// Layer switch
#define NUM LT(_NUM, KC_BSPC)
#define SYM LT(_SYM, KC_SPC)
#define G_NUM LT(_NUM, KC_G)

// Shift Enter
#define ENT_LS LSFT_T(KC_ENT)
#define ESC_RS RSFT_T(KC_ESC)

#define C_CAP LCTL_T(CW_TOGG)

// Home Row Mods
#define W_A LGUI_T(KC_A)
#define W_S LALT_T(KC_S)
#define W_D LSFT_T(KC_D)
#define W_F LCTL_T(KC_F)

#define W_J RCTL_T(KC_J)
#define W_K LSFT_T(KC_K)
#define W_L LALT_T(KC_L)
#define W_SC RGUI_T(KC_SCLN)

#define M_A LCTL_T(KC_A)
#define M_S LALT_T(KC_S)
#define M_D LSFT_T(KC_D)
#define M_F LGUI_T(KC_F)

#define M_J RGUI_T(KC_J)
#define M_K LSFT_T(KC_K)
#define M_L LALT_T(KC_L)
#define M_SC RCTL_T(KC_SCLN)

// snake case mode
bool space_underscore_toggle = false;
void dance_cln_finished (tap_dance_state_t *state, void *user_data) {
  space_underscore_toggle = !space_underscore_toggle;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SNAKE] = ACTION_TAP_DANCE_FN(dance_cln_finished),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WIN] = LAYOUT_split_3x6_5(
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    CW_TOGG, W_A    , W_S    , W_D    , W_F    , G_NUM  ,   KC_H   , W_J    , W_K    , W_L    , W_SC   , KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
   TD_SNAKE, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_MPLY, QK_REP , NUM    , ENT_LS , QK_LOCK,   _______, ESC_RS , SYM    , KC_TAB , KC_MNXT
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_MAC] = LAYOUT_split_3x6_5(
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    CW_TOGG, M_A    , M_S    , M_D    , M_F    , G_NUM  ,   KC_H   , M_J    , M_K    , M_L    , M_SC   , KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
   TD_SNAKE, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_MPLY, QK_REP , NUM    , ENT_LS , QK_LOCK,   _______, ESC_RS , SYM    , KC_TAB , KC_MNXT
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_NUM] = LAYOUT_split_3x6_5(
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, D_MAIN , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,   KC_CAPS, KC_7   , KC_8   , KC_9   , KC_PLUS, RESET  ,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, D_MAC  , KC_F4  , KC_F5  , KC_F6  , KC_F11 ,   KC_TAB , KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL ,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, QK_BOOT, KC_F1  , KC_F2  , KC_F3  , KC_F12 ,   KC_EQL , KC_1   , KC_2   , KC_3   , KC_ASTR, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_MPLY, _______, FINGER , _______, _______,   _______, _______, KC_0   , _______, _______
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_SYM] = LAYOUT_split_3x6_5(
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    _______, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC,   KC_CIRC, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC,   KC_DLR , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    _______, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,   KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_MPLY, _______, _______, _______, _______,   _______, _______, FINGER , _______, _______
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case D_MAIN:
          if (record->event.pressed) {
              set_single_persistent_default_layer(_WIN);
          }
          return false; // Stops further processing of this keypress
      break;

      case D_MAC:
          if (record->event.pressed) {
              set_single_persistent_default_layer(_MAC);
          }
          return false; // Stops further processing of this keypress
      break;

      case KC_SPC: // Assuming KC_SPC is the keycode for the spacebar
          if (space_underscore_toggle) {
              if (record->event.pressed) {
                  // Send an underscore instead of a space
                  tap_code16(KC_UNDS);
                  return false; // Stops further processing of this keypress
              }
          }
          // If space_underscore_toggle is not active, process normally
          break;
  }


  return true; // Process all other keypresses normally
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   switch (get_highest_layer(state)) {
//     case _WIN:
//         rgblight_setrgb(RGB_BLUE);
//         break;
//     case _NUM:
//         rgblight_setrgb(RGB_RED);
//         break;
//     case _SYM:
//         rgblight_setrgb(RGB_RED);
//         break;
//     default: // for any other layers, or the default layer
//         rgblight_setrgb (RGB_WHITE);
//         break;
//   }
//   return state;
// }

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
*/
