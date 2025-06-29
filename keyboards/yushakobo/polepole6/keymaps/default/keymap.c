// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_2x6(
        LCTL(KC_KP_MINUS),    LCTL(KC_KP_PLUS),    KC_MUTE,
        LCTL(KC_Z),           LCTL(KC_X),          LCTL(KC_C),      LCTL(KC_V),
        KC_NO,                KC_NO
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)}
};
#endif
