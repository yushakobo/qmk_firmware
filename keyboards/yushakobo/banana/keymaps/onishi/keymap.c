// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_4x13(

        KC_ESC,  KC_Q,    KC_L,   KC_U,  KC_COMM, KC_DOT,  KC_F,      KC_W, KC_R,  KC_Y,  KC_P,    KC_BSPC,
        KC_TAB,  KC_E,    KC_I,   KC_A,  KC_O,    KC_MINS, KC_K,      KC_T, KC_N,  KC_S,  KC_H,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,   KC_C,  KC_V,    KC_SCLN, KC_G,      KC_D, KC_M,  KC_J,  KC_B,    KC_UP,   KC_SLSH,
        KC_LCTL, KC_LALT, KC_DEL, MO(1), KC_SPC,           A(KC_GRV),       MO(2), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT

    )
};
