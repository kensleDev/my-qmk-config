#include QMK_KEYBOARD_H
enum layer_number {
    _WIN = 0,
    _MAC,
    _NUM,
    _NAV,
    _PUNC,
    _FUNCT,
    _GAME,
    _GAME_SHIFT,
    _STREAM
};


/// ------------------------------------------------  variables
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define FINGER KC_TRNS

#define NUM LT(_NUM, KC_BSPC)
#define NAV LT(_NAV, KC_SPC)
#define H_FUNC LT(_FUNCT, KC_H)
#define G_NUM LT(_NUM, KC_BSPC)

#define D_MAIN DF(_WIN)
#define D_MAC DF(_MAC)

#define LAUNCH G(KC_SLSH)

// PROGRAMS 
#define P1 C(A(S(KC_1)))
#define P2 C(A(S(KC_2)))
#define P3 C(A(S(KC_3)))
#define P4 C(A(S(KC_4)))
#define P5 C(A(S(KC_5)))
#define P6 C(A(S(KC_6)))
#define P7 C(A(S(KC_7)))
#define P8 C(A(S(KC_8)))
#define P9 C(A(S(KC_9)))

// Left-hand home row mods
#define W_A LGUI_T(KC_A)
#define W_S LALT_T(KC_S)
#define W_D LSFT_T(KC_D)
#define W_F LCTL_T(KC_F)

// Right-hand home row mods
#define W_J RCTL_T(KC_J)
#define W_K LSFT_T(KC_K)
#define W_L LALT_T(KC_L)
#define W_SC RGUI_T(KC_SCLN)


// Left-hand home row mods
#define M_A LCTL_T(KC_A)
#define M_S LALT_T(KC_S)
#define M_D LSFT_T(KC_D)
#define M_F LGUI_T(KC_F)

// Right-hand home row mods
#define M_J RGUI_T(KC_J)
#define M_K LSFT_T(KC_K)
#define M_L LALT_T(KC_L)
#define M_SC RCTL_T(KC_SCLN)
/// ------------------------------------------------  combos

enum combos {
  CO_TAB,
  CO_GUI,
  CO_CAPS,
  CO_DELW,
  CO_ESC,
//   CO_COPY,
//   CO_PASTE
};

const uint16_t PROGMEM tab_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_F, KC_Q, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_Q, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_Q, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CO_TAB] = COMBO(tab_combo, KC_TAB),
  [CO_GUI] = COMBO(gui_combo, KC_LGUI),
  [CO_CAPS] = COMBO(caps_combo, KC_CAPS),
};

enum keycodes {
    CLEAR
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WIN] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , XXXXXXX, XXXXXXX, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      W_A    , W_S    , W_D    , W_F    , G_NUM  , XXXXXXX, XXXXXXX, H_FUNC , W_J    , W_K    , W_L    , W_SC   ,
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────-────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, KC_DEL , NUM    , KC_ENT ,      XXXXXXX    , KC_ESC , NAV    , LAUNCH , XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴────────-────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_MAC] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , XXXXXXX, XXXXXXX, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      M_A    , M_S    , M_D    , M_F    , G_NUM  , XXXXXXX, XXXXXXX, H_FUNC , M_J    , M_K    , M_L    , M_SC   , 
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
  //├────────┼────────┼────────┼────────┼────────┼────────-────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, KC_DEL , NUM    , KC_ENT ,      XXXXXXX    , KC_ESC , NAV    , LAUNCH , XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴────────-────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┬────────┬────────┬────────┬────────┬────────┐
      KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC, XXXXXXX, XXXXXXX, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC, XXXXXXX, XXXXXXX, KC_DLR , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, XXXXXXX, XXXXXXX, KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼─────────────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     XXXXXXX     , FINGER , RESET  , XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┌────────┬────────┬────────┬────────┬────────┬────────┐
      D_MAIN , KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX, XXXXXXX, _______, KC_7   , KC_8   , KC_9   , KC_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      D_MAC  , KC_F4  , KC_F5  , KC_F6  , KC_F11 , XXXXXXX, XXXXXXX, KC_TAB , KC_4   , KC_5   , KC_6   , KC_MINS, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , XXXXXXX, XXXXXXX, KC_EQL , KC_1   , KC_2   , KC_3   , KC_ASTR,
  //├────────┼────────┼────────┼────────┼────────┼─────────────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     XXXXXXX     , KC_DOT , KC_0   , _______, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴────────-────────┴────────┴────────┴────────┴────────┴────────┘
  ),



};


// ------ ------------------------------------------ macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    


    switch (keycode) {

        case CLEAR:
        if (record->event.pressed) {
            layer_clear();

        }
        break;

        case D_MAIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            }
            return false;
        break;
        case D_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
        break;
   };
   return true;
}


  //[_PUNC] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┬────────┬────────┬────────┬────────┬────────┐
  //    KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
  //    KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC, XXXXXXX, XXXXXXX, KC_DLR , _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
  //    KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, XXXXXXX, XXXXXXX, KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD,
  //├────────┼────────┼────────┼────────┼────────┼─────────────────┼────────┼────────┼────────┼────────┼────────┤
  //    XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BTN4,     XXXXXXX     , RESET  , FINGER , XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
  //),

  //  [_FUNCT] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┬────────┬────────┬────────┬────────┬────────┐
  //    KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
  //    KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______, XXXXXXX, XXXXXXX, FINGER , _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
  //    KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼─────────────────┼────────┼────────┼────────┼────────┼────────┤
  //    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     XXXXXXX     , _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
  //),