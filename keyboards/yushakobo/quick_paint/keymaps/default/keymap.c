#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            LCTL(KC_Z), LCTL(KC_Y), KC_G, KC_P, KC_LALT,
            KC_M, LCTL(KC_SPC), KC_E, KC_B, KC_NO,
            KC_W, LSFT(KC_SPC), KC_K, KC_SPC, KC_NO
        )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_RBRC, KC_BSLS)}
};
#endif
