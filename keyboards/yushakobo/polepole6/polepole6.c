/* Copyright 2020 monksoffunk
 * Copyright 2022 sekigon-gonnoc
 * Copyright 2022 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "polepole6.h"

user_config_t user_config;

uint8_t  encoderlocklayer[NUM_ENCODERS]  = {0};
uint8_t  encoder_modifier                = 0;
uint16_t encoder_modifier_pressed_ms     = 0;

extern bool is_encoder_action;

#ifndef ENCODER_MODIFIER_TIMEOUT_MS
#    define ENCODER_MODIFIER_TIMEOUT_MS 250
#endif

void eeconfig_init_kb(void) {
    user_config.raw               = 0;
    user_config.mac_mode          = true;
    eeconfig_update_kb(user_config.raw);
    eeconfig_init_user();
}

void keyboard_pre_init_kb(void) {
    // Read the user config from EEPROM
    user_config.raw              = eeconfig_read_kb();
    keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui =
        !user_config.mac_mode;
    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    debug_enable   = true;
    debug_keyboard = true;

    keyboard_post_init_user();
}

void matrix_scan_kb(void) {
    encoder_action_unregister(encoderlocklayer);
    if (encoder_modifier != 0 && timer_elapsed(encoder_modifier_pressed_ms) >
                                     ENCODER_MODIFIER_TIMEOUT_MS) {
        unregister_mods(encoder_modifier);
        encoder_modifier = 0;
    }
    matrix_scan_user();
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise, encoderlocklayer);
    return true;
}

bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    if (encoder_modifier != 0 && !is_encoder_action) {
        unregister_mods(encoder_modifier);
        encoder_modifier = 0;
    }

    switch (keycode) {
        case QK_MODS ... QK_MODS_MAX:
            if (is_encoder_action) {
                if (record->event.pressed) {
                    uint8_t current_mods        = keycode >> 8;
                    encoder_modifier_pressed_ms = timer_read();
                    if (current_mods != encoder_modifier) {
                        del_mods(encoder_modifier);
                        encoder_modifier = current_mods;
                        add_mods(encoder_modifier);
                    }
                    register_code(keycode & 0xff);
                } else {
                    unregister_code(keycode & 0xff);
                }
                return false;
            } else {
                return true;
            }
            break;
        case AG_NORM:
            if (record->event.pressed) {
                if (!user_config.mac_mode) {
                    user_config.mac_mode = true;
                    eeconfig_update_kb(user_config.raw);
                }
            }
            return true;
            break;
        case AG_SWAP:
            if (record->event.pressed) {
                if (user_config.mac_mode) {
                    user_config.mac_mode = false;
                    eeconfig_update_kb(user_config.raw);
                }
            }
            return true;
            break;
        case ENC_00 ... ENC_09:
            if (record->event.pressed) {
                if (encoderlocklayer[0] != keycode - ENC_00) {
                    encoderlocklayer[0] = keycode - ENC_00;
                } else {
                    encoderlocklayer[0] = 0;
                }
            }
            return false;
            break;
        default:
            break;
    }
    return process_record_user(keycode, record);
}
