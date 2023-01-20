// Copyright 2023 D Patrick Seal (@plasticrake)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

enum userspace_custom_keycodes {
#if defined(VIA_ENABLE)
    VRSN = USER00,
#else
    VRSN = SAFE_RANGE,
#endif
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD,

    // USER_MOUSE_JIGGLE_ENABLE
    MS_JIGL,

    // USER_SECRETS_ENABLE
    K_SECR1,
    K_SECR2,
    K_SECR3,
    K_SECR4,
    K_SECR5,

#if defined(VIA_ENABLE)
    NEW_SAFE_RANGE = SAFE_RANGE,
#else
    NEW_SAFE_RANGE,
#endif

};

// macOS
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

// Windows 10 shortcuts: change desktop to the left/right
#define WN_DSKL C(G(KC_LEFT))
#define WN_DSKR C(G(KC_RGHT))

// MS Teams
#define KC_TEAMS_CAM C(S(KC_O))
#define KC_TEAMS_MUTE C(S(KC_M))
