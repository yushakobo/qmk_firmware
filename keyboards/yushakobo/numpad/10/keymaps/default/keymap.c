// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │ 0     │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT(
        KC_A,
        KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        LT(1,KC_P0),      KC_PDOT
    ),

    /*
     * ┌───┐───┬───┬───┐
     * │Num│ / │ * │ - │
     * ┌───┬───┬───┐───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │mid│ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [1] = LAYOUT(
        KC_NO,
        _______, _______, _______, _______,
        KC_HOME, KC_UP,   KC_PGUP, _______,
        KC_LEFT, MS_BTN3, KC_RGHT,
        KC_END,  KC_DOWN, KC_PGDN, _______,
        KC_INS,           KC_DEL
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

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif