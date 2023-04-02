// Copyright 2023 Yushakobo (@tim432)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// map encoder to matrix (col, row)
#define ENCODERS_CCW_KEY { { 0, 2 } }
#define ENCODERS_CW_KEY  { { 1, 2 } }

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
