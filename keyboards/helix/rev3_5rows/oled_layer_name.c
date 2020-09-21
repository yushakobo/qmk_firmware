/* Copyright 2020 yushakobo
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

/*
   How to Customize

   $ make helix/rev3_5rows:YOUR_KEYMAP:clean
   $ cp keyboards/helix/rev3_5rows/oled_layer_name.c keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP

   $ edit keyboards/helix/rev3_5rows/keymaps/YOUR_KEYMAP/oled_layer_name.c
   $ make helix/rev3_5rows:YOUR_KEYMAP
   $ make helix/rev3_5rows:YOUR_KEYMAP:flash
 */

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

#ifdef OLED_DRIVER_ENABLE
const char * PROGMEM get_layer_name(uint8_t layernum) {
    switch (layernum) {
    case _QWERTY:
        return PSTR("Default\n");
        break;
    case _RAISE:
        return PSTR("Raise\n");
        break;
    case _LOWER:
        return PSTR("Lower\n");
        break;
    case _ADJUST:
        return PSTR("Adjust\n");
        break;
    default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        return PSTR("Undefined");
    }
}
#endif
