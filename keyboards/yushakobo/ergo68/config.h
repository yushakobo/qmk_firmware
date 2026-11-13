// Copyright 2023 yushakobo
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// rgblight の split 同期を有効にする。
// QMK は USE_I2C の場合のみ RGBLIGHT_SPLIT を自動定義するため
// (quantum/split_common/post_config.h)、serial トランスポートでは明示が必要。
// 未定義だと PUT_RGBLIGHT トランザクションが登録されず、slave 側の LED が
// マスターの状態に追従しない。
#define RGBLIGHT_SPLIT
