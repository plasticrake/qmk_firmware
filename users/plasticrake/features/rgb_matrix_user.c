// Copyright 2023 D Patrick Seal (@plasticrake)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "rgb_matrix_user.h"

#include "rgb_matrix.h"
#include "lib/lib8tion/lib8tion.h"

#include "plasticrake.h"

extern led_config_t g_led_config;

RGB clip_value(uint8_t hue, uint8_t sat, uint8_t val, uint8_t max_val) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > max_val) {
        hsv.v = max_val;
    }
    return hsv_to_rgb(hsv);
}

void set_color_mapped_keys(uint8_t layer, uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min,
                           uint8_t led_max) {
    RGB rgb = clip_value(hue, sat, val, rgb_matrix_get_val());

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
            }
        }
    }
}

__attribute__((weak)) void rgb_matrix_indicator_keymap(void) {}

void keyboard_post_init_rgb_matrix(void) {}

void matrix_scan_rgb_matrix(void) {
    rgb_matrix_indicator_keymap();
}

bool process_record_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_keymap(led_min, led_max)) {
        return false;
    }

    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case 0:
            break;
        case 1:
            set_color_mapped_keys(layer, HSV_RED, led_min, led_max);
            break;
        case 2:
            set_color_mapped_keys(layer, HSV_YELLOW, led_min, led_max);
            break;
        case 3:
            set_color_mapped_keys(layer, HSV_GREEN, led_min, led_max);
            break;
        default:
            break;
    }
    return false;
}

__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) {
    return true;
}

bool rgb_matrix_indicators_user(void) {
    return rgb_matrix_indicators_keymap();
}
