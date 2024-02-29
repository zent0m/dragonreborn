// Copyright 2022 Zentom
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdio.h>
 
#include "layer_names.h"

#include "oled_lib/bongocat.c"
#include "oled_lib/eyes.c"
#include "oled_lib/luna.c"
#include "oled_lib/dragonreborn.c"
//#include "oled_lib/r6.c"

char wpm_str[10];  // Used by the WPM enabled OLED effects (?)

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;   // Rotates the OLED screen 180 degrees
}

bool funcPress = false;   // Used for Function layer state display functionality below

bool oled_task_user(void) {
    led_t led_state = host_keyboard_led_state();
    static uint8_t old_layer;
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    
    // Layer Change OLED Clear by HorrorTroll
    if ((layer != old_layer) && (layer != 4)) {
        oled_clear();   // Clear the OLED Screen when layers are switched, but not when the Function layer is accessed
    }

    // Functionality to display the state of the Function layer differently according to the layer. Underlying functionality by HorrorTroll
    if (layer == 4) {
        if (old_layer == 3) {   // Function indiciator for Bongocat
            oled_set_cursor(0, 2);
            oled_write_P(funcPress ? PSTR("FUNC") : PSTR("    "), false);
        } else if (old_layer == 0) {   // Function indicator for Luna the dog
            oled_set_cursor((oled_max_chars()/2) + 4, 2);
            oled_write_P(funcPress ? PSTR("Bork!") : PSTR("    "), false);
        }      
    }

    old_layer = layer;

    switch (layer) {
        case 0:
            render_luna((oled_max_chars() / 2) - 2, 0, 15, 0);  // Render Luna the pet dog. (luna X pos, luna Y pos, QMK X pos, QMK Y pos) Note that Luna is 4 lines tall, so Y settings must be 0 on 128x32 displays.
            oled_set_cursor(0, 1);                              // Prints CAPS on new line if it's on
            oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
            break;
        // Insert case 3 here in case it's used. Removed it because the functionality to display the state of Function has already been discussed above
        case 3:
            render_bongocat();                                // Render Bongocat itself
            oled_set_cursor(0, 0);                            // Sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
            sprintf(wpm_str, "WPM:%03d", get_current_wpm());  // Edit the string to change what shows up. Edit %03d to change how many digits show up.
            oled_write(wpm_str, false);                       // Writes wpm on top left corner of string
            oled_set_cursor(0, 1);                            // Prints CAPS on new line if it's on
            oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("       "), false);
            return false;
            break;
        case 2:
            render_eyes();   // Custom blinking eyes animation by Zentom
            return false;
            break;
        case 1:
            render_dragon();  // Custom Dragonreborn animation by Zentom
            return false;
            break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
        switch (keycode) {
            case MO(_FN):   // Enable a flag to run the function state identifier logic above
                if (record->event.pressed) {
                    funcPress = true;
                } else {
                    funcPress = false;
                }
                break;
            case KC_LALT:   // Enable a flag to make Luna sneak, and for R6 Alt Walking
                if (record->event.pressed) {
                    isSneaking = true;

                    /*if (altWalk) {
                        altWalk = false;
                    } else {
                        altWalk = true;
                    }*/

                } else {
                    isSneaking = false;
                }
                break;
            //case KC_LCTL:  // Enable a flag for R6 Proning
            //    if (record->event.pressed) {
            //        if (proneCheck) {
            //            proneCheck = false;
            //        } else {
            //            proneCheck = true;
            //        }
            //    }
            //    break;
            //case KC_C:  // Enable a flag for R6 Crouching
            //    if (record->event.pressed) {
            //        if (crouchWalk) {
            //            crouchWalk = false;
            //        } else {
            //            crouchWalk = true;
            //        }
            //    }
            //    break;
            case KC_SPC:   // Enable a flag to make Luna jump
                if (record->event.pressed) {
                    isJumping  = true;
                    showedJump = false;
                } else {
                    isJumping = false;
                }
                break;
        }
        return true;
}

#endif
