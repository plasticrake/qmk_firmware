// Copyright 2023 D Patrick Seal (@plasticrake)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "plasticrake.h"

#include QMK_KEYBOARD_H

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
#if defined(RGB_MATRIX_ENABLE)
    keyboard_post_init_rgb_matrix();
#endif

    keyboard_post_init_keymap();
}
