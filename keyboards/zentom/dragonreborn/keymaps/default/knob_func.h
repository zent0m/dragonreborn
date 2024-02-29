// Copyright 2022 Zentom
// SPDX-License-Identifier: GPL-2.0-or-later

// layer_names.h is already included in oled_func.h, so no need to include it here or it throws a duplication error.

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state | default_layer_state) == 0) {
        if (index == 0) {
            if (clockwise) {
                tap_code_delay(KC_MPRV, 100);
            } else {
                tap_code_delay(KC_MNXT, 100);
            }
        }
    } else if (get_highest_layer(layer_state | default_layer_state) == 4){
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}

#endif
