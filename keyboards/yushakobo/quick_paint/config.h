// Copyright 2022 yushakobo (@yushakobo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define WS2812_PIO_USE_PIO1

// map encoder to matrix (col, row)
#define ENCODERS_CCW_KEY { { 4, 1 } }
#define ENCODERS_CW_KEY  { { 4, 2 } }


#define LAYER_STATE_32BIT

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
