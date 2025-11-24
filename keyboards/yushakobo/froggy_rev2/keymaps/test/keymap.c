// Copyright 2021 QMK / NachoxMacho
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
    * ,-----------------------------------------.
    * |  C+z |   ;  |   [  |   (  |   <  |   {  |
    * |------+------+------+------+------+------|
    * | KANA |   P  |   K  |   R  |   A  |   F  |
    * |------+------+------+------+------+------+------.
    * |  BS  |   D  |   T  |   H  |   E  |   O  |      |
    * |------+------+------+------+------+------+------|
    * | Shift|   Y  |   S  |   N  |   I  |   U  |Space |
    * |------+------+------+------+------+------+------|
    * | Ctrl | Alt  | Gui  | Sym  | Num  | OPT  | Ent  |
    * `------------------------------------------------'
    */
    [0] = LAYOUT( \
        LCTL(KC_Z),    KC_SCLN,       KC_LBRC,       KC_LPRN,   KC_LT,     KC_LCBR,    KC_NO,   \
        _______,       KC_P,          KC_K,          KC_R,      KC_A,      KC_F,       KC_NO,   \
        KC_BSPC,       KC_D,          KC_T,          KC_H,      KC_E,      KC_O,       _______, \
        OSM(MOD_LSFT), KC_Y,          KC_S,          KC_N,      KC_I,      KC_U,       KC_SPC,  \
        OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_LGUI),            KC_NO,     _______,    KC_ENT   \
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_RBRC, KC_BSLS)}
};
#endif
