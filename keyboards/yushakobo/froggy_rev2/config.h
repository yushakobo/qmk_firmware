// Copyright 2025 yushakobo
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

/* Audio settings */
#ifdef AUDIO_ENABLE
  #define AUDIO_PIN GP7
  #define AUDIO_PWM_DRIVER PWMD3
  #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
  #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

/* trackball settings*/
#ifdef POINTING_DEVICE_ENABLE
    #define PMW33XX_CS_PIN GP9
    #define SPI_SCK_PIN GP10
    #define SPI_MOSI_PIN GP11
    #define SPI_MISO_PIN GP8
    #define PMW33XX_CS_PIN GP21 // SPI CS pin.
    #define PMW33XX_CPI 1600
    #define PMW33XX_CLOCK_SPEED 2000000
    #define MOUSE_EXTENDED_REPORT
    #define POINTING_DEVICE_INVERT_X
#endif
