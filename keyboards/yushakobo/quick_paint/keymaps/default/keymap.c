#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            LCTL(KC_Z), LCTL(KC_Y), KC_G, KC_P, KC_LALT,
            KC_M, LCTL(KC_SPC), KC_E, KC_B, KC_RBRC,
            KC_W, LSFT(KC_SPC), KC_K, KC_SPC, KC_BSLS
        )
};

