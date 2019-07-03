#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FUNCD 1
//#define _RESERVED 2
#define FN_SCRCAPT LSFT(LCMD(KC_3)) //Screen Capture(Shift+CMD+3)
#define FN_SCRCAPTSEL LSFT(LCMD(KC_4)) //Screen Capture Selected(Shift+CMD+4)
#define FN_SCLK LCMD(LCTL(KC_Q)) //Screen Lock(CMD+CTL+Q)
#define FN_VOLD KC__VOLDOWN //Volume Down
#define FN_VOLU KC__VOLUP   //Volume Up
#define FN_VSC_FOCSTERM LCMD(KC_M) //Focus on terminal(for VSCode)
#define FN_VSC_FOCSEDIT LCMD(KC_1) //Focus on first editor group(for VSCode)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FUNCD,
//  RESERVED,
};

//Tap Dance Definitions
enum {
  TD_LBRC_LCBR = 0,
  TD_RBRC_RCBR,
  TD_BSLS_PIPE,
  TD_GRV_TILD,
  TD_QUOT_DQT,
  TD_F3_SCRCAPT,
  TD_F4_SCRCAPTSEL,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR), // [ or double tap {
  [TD_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR), // ] or double tap }
  [TD_BSLS_PIPE]  = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE), // \ or double tap |
  [TD_GRV_TILD]   = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),  // ` or double tap ~
  [TD_QUOT_DQT]   = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),  // ' or double tap "
  [TD_F3_SCRCAPT] = ACTION_TAP_DANCE_DOUBLE(KC_F3, FN_SCRCAPT), // F3 or double tap Screen Capture
  [TD_F4_SCRCAPTSEL] = ACTION_TAP_DANCE_DOUBLE(KC_F4, FN_SCRCAPTSEL), // F3 or double tap Screen Capture Selected
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( 
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                               KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RCTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    FUNCD,             KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCMD, KC_ESC,                    KC_ENT,  KC_RCMD,  KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FUNCD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______,   KC_F1,   KC_F2, TD(TD_F3_SCRCAPT),               _______, _______, TD(TD_LBRC_LCBR), TD(TD_RBRC_RCBR), TD(TD_BSLS_PIPE), TD(TD_GRV_TILD),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, FN_SCLK, _______, TD(TD_F4_SCRCAPTSEL), KC_F5, KC_F6,                _______, FN_VSC_FOCSTERM, FN_VSC_FOCSEDIT, _______, _______, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,   KC_F7,   KC_F8,   KC_F9,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,TD(TD_QUOT_DQT), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,  KC_F10,  KC_F11,  KC_F12, _______,          _______, _______, _______, FN_VOLD, FN_VOLU, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )

//  [_RESERVED] = LAYOUT(
//  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                    _______, _______, _______,                   _______, _______, _______
//                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case FUNCD:
      if (record->event.pressed) {
        layer_on(_FUNCD);
      } else {
        layer_off(_FUNCD);
      }
      return false;
      break;
    //case RESERVED:
    //  if (record->event.pressed) {
    //    layer_on(_RESERVED);
    //  } else {
    //    layer_off(_RESERVED);
    //  }
    //  return false;
    //  break;
  }
  return true;
}
