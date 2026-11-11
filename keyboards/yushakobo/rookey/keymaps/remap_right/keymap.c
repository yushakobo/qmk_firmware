// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LCTL(KC_A),     LSFT(KC_END),   LSFT(KC_HOME),  LT(2, KC_BSPC),
        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCS(KC_V),
                                                                        LT(1, KC_ENT)
    ),
    [1] = LAYOUT(
        KC_F11,         LCTL(KC_T),     LCTL(KC_F),     LSG(KC_S),
        LGUI(KC_RGHT),  LGUI(KC_LEFT),  MS_WHLR,        MS_WHLL,
                                                                        KC_TRNS
    ),
    [2] = LAYOUT(
        KC_ESC,         LCTL(KC_W),     LALT(KC_LEFT),  KC_TRNS,
        LGUI(KC_L),     KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        LCTL(KC_Z)
    ),
    [3] = LAYOUT(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                        KC_TRNS
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif