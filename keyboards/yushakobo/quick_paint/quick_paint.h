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

#pragma once

#include "quantum.h"
#include "encoder_action.h"

typedef union {
    uint32_t raw;
    struct {
        bool mac_mode : 1;
    };
} user_config_t;

enum kb_keycodes {
    ENCADJ = 0xC0,
    UNUSED00,
    UNUSED01,
    ENC_00,
    ENC_01,
    ENC_02,
    ENC_03,
    ENC_04,
    ENC_05,
    ENC_06,
    ENC_07,
    ENC_08,
    ENC_09,
    USR_SAFE_RANGE,
};
