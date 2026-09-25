// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC,     KC_NO,      KC_BSPC,    KC_DEL,
        KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,
        KC_P7,      KC_P8,      KC_P9,
        KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
        KC_P1,      KC_P2,      KC_P3,
        LT(1,KC_P0),KC_PDOT,                KC_PENT
    ),


    [1] = LAYOUT(
        QK_BOOT,    _______,    _______,    _______,
        _______,    S(KC_TAB),  KC_TAB,     KC_PEQL,
        KC_HOME,    KC_UP,      KC_PGUP,
        KC_LEFT,    MS_BTN3,    KC_RGHT,    _______,
        KC_END,     KC_DOWN,    KC_PGDN,
        _______,    _______,                _______
    )
};

#ifdef RGBLIGHT_LAYERS
# define LOCK_COLOR_1 HSV_TEAL

const rgblight_segment_t PROGMEM numpad_a_default[] = RGBLIGHT_LAYER_SEGMENTS (
    {0,1,HSV_WHITE}
);

const rgblight_segment_t PROGMEM numpad_a_numlock[] = RGBLIGHT_LAYER_SEGMENTS (
    {0,1,LOCK_COLOR_1}
);

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 0));
    return state;
}

bool led_update_user(led_t led_state){
    rgblight_set_layer_state(1, (host_keyboard_led_state().num_lock));
    return true;
}

const rgblight_segment_t* const PROGMEM numpad_a_rgb_layers[] = RGBLIGHT_LAYERS_LIST (
  numpad_a_default,
  numpad_a_numlock
);

void keyboard_post_init_user(void) {
    rgblight_sethsv(0,0,5);
    rgblight_layers = numpad_a_rgb_layers;
}

#endif