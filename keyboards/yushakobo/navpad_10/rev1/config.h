/*
Copyright 2021 yushakobo

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x3265
#define PRODUCT_ID   0x0008 //not confirmed
#define DEVICE_VER   0x0001
#define MANUFACTURER yushakobo
#define PRODUCT      "navpad 1.0"

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, F4 }
#define MATRIX_COL_PINS { F5, F6, B2, B3, B1, F7 }
#define UNUSED_PIN { D1, D0 }

#ifdef RGB_ENABLE
#    define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 8, 7 }
#endif
