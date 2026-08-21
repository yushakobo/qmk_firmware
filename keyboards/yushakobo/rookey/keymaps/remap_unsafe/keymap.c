// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LCTL(KC_A),     LCTL(KC_T),     KC_F2,          LT(2, KC_BSPC),
        LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCS(KC_V),
        LT(1, KC_ENT)
    ),
    [1] = LAYOUT(
        LSG(KC_S),      LCTL(KC_W),     LALT(KC_LEFT),  LCTL(KC_Z),
        LGUI(KC_LEFT),  LGUI(KC_RGHT),  MS_WHLL,        MS_WHLR,
        KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,
        KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,
        KC_TRNS
    ),
    [3] = LAYOUT(
        KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,
        KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,
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