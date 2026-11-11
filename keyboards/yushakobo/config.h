// Copyright 2026 yushakobo
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Secure: VIA/Remap のマトリクス状態取得を、物理操作で一時的に許可する。
// 以下はいずれもコンパイル時定数なので、VIA/Remap からは変更できない。

// 解除シーケンス（固定物理位置）。全キーボードに存在する座標のみを使う。
#ifndef SECURE_UNLOCK_SEQUENCE
#    define SECURE_UNLOCK_SEQUENCE {{0, 1}}
#endif

// 解除要求からシーケンス入力までの猶予 (ms)
#ifndef SECURE_UNLOCK_TIMEOUT
#    define SECURE_UNLOCK_TIMEOUT 5000
#endif

// 解除後の自動再ロック (ms)。secure_activity_event() は呼ばないので、
// 解除時刻からこの時間が経過すると必ずロックへ戻る。
#ifndef SECURE_IDLE_TIMEOUT
#    define SECURE_IDLE_TIMEOUT 120000
#endif

// 解除要求トリガ: 固定物理位置の長押し
#ifndef YUSHAKOBO_SECURE_TRIGGER_ROW
#    define YUSHAKOBO_SECURE_TRIGGER_ROW 0
#endif
#ifndef YUSHAKOBO_SECURE_TRIGGER_COL
#    define YUSHAKOBO_SECURE_TRIGGER_COL 0
#endif
#ifndef YUSHAKOBO_SECURE_TRIGGER_HOLD_MS
#    define YUSHAKOBO_SECURE_TRIGGER_HOLD_MS 1500
#endif
