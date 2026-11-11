// Copyright 2026 yushakobo
// SPDX-License-Identifier: GPL-2.0-or-later

// yushakobo 配下の全キーボード共通の Secure トリガ。
//
// 固定した物理位置を長押しすると解除要求を出し、続けて SECURE_UNLOCK_SEQUENCE の
// 位置を押すと解除される。解除中は VIA/Remap のマトリクス状態取得が許可され、
// SECURE_IDLE_TIMEOUT の経過で自動的に再ロックされる。
//
// 座標で判定するため、VIA/Remap でキーコードを書き換えても解除操作は失われない。
// なお長押し中はそのキー本来の動作も実行される（押下を抑止しない）。

#include "quantum.h"

#if defined(SECURE_ENABLE)

#    include "secure.h"

static uint32_t trigger_hold_start = 0;
static bool     trigger_held       = false;
static bool     trigger_fired      = false;

void matrix_scan_kb(void) {
    bool held = matrix_is_on(YUSHAKOBO_SECURE_TRIGGER_ROW, YUSHAKOBO_SECURE_TRIGGER_COL);

    if (held && !trigger_held) {
        trigger_hold_start = timer_read32();
        trigger_fired      = false;
    }

    if (held && !trigger_fired && timer_elapsed32(trigger_hold_start) >= YUSHAKOBO_SECURE_TRIGGER_HOLD_MS) {
        trigger_fired = true;

        if (secure_is_locked()) {
            secure_request_unlock();
        } else {
            // 解除中・解除待ちからの長押しは即ロック（トグル）
            secure_lock();
        }
    }

    trigger_held = held;

    matrix_scan_user();
}

#endif
