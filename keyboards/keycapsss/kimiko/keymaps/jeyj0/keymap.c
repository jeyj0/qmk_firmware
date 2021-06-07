/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
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

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _HANDS_ON,
    _NUM,
    _NAV,
    _SETTINGS,
};

#define HANDS    DF(_HANDS_ON)
#define QWERTY   DF(_QWERTY)
#define NUM_SPC  LT(_NUM, KC_SPC)
#define NUM_E    LT(_NUM, KC_E)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define NAV_ENT  LT(_NAV, KC_ENT)
#define LT_SETT  LT(_SETTINGS, _______)

#define SFT_KCF  LSFT_T(KC_F)
#define SFT_KCJ  RSFT_T(KC_J)
#define SFT_KCT  LSFT_T(KC_T)
#define SFT_KCA  RSFT_T(KC_A)
#define SFT_RPRN LSFT_T(KC_RPRN)
#define SFT_KC4  RSFT_T(KC_4)
#define SFT_RGHT LSFT_T(KC_RGHT)
#define SFT_LEFT RSFT_T(KC_LEFT)

#define COM_QUS  KC_COMM
#define DOT_EXC  KC_DOT
#define SLS_BSL  KC_SLSH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_ESC,  KC_A,    KC_S,    KC_D,    SFT_KCF, KC_G,                        KC_H,    SFT_KCJ, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     XXXXXXX, XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                      KC_CAPS, KC_LGUI, KC_LGUI, NUM_E,    NAV_BSPC,NAV_ENT,  NUM_SPC, KC_RALT, KC_RGUI, KC_CAPS
),

[_HANDS_ON] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_Q,    KC_Z,    XXXXXXX, XXXXXXX,
    _______, KC_W,    KC_G,    KC_M,    KC_P,    KC_ESC,                      KC_QUOT, KC_U,    KC_K,    KC_J,    KC_SCLN, XXXXXXX,
    XXXXXXX, KC_R,    KC_S,    KC_N,    SFT_KCT, KC_B,                        KC_Y,    SFT_KCA, KC_O,    KC_I,    KC_H,    XXXXXXX,
    _______, KC_X,    KC_C,    KC_L,    KC_D,    KC_V,     XXXXXXX, XXXXXXX,  KC_MINS, KC_F,    COM_QUS, DOT_EXC, SLS_BSL, _______,
                      _______, _______, _______, NUM_E,    _______, _______,  _______, _______, _______, _______
),

[_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    _______, _______, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                     KC_AT,   KC_7,    KC_8,    KC_9,    _______, _______,
    _______, KC_HASH, KC_EQL,  KC_LPRN, SFT_RPRN,KC_TILD,                     KC_CIRC, SFT_KC4, KC_5,    KC_6,    KC_DLR,  _______,
    _______, _______, KC_ASTR, KC_LT,   KC_GT,   KC_GRV,   _______, _______,  KC_AMPR, KC_1,    KC_2,    KC_3,    KC_PIPE, _______,
                      _______, _______, _______, _______,  _______, _______,  KC_0,    _______, _______, _______
),

[_NAV] = LAYOUT(
    LT_SETT, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, LT_SETT,
    _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______,                     _______, KC_PGDN, KC_UP,   KC_PGUP, _______, _______,
    _______, KC_HOME, KC_LEFT, KC_DOWN, SFT_RGHT,KC_END,                      KC_HOME, SFT_LEFT,KC_DOWN, KC_RGHT, KC_END,  _______,
    _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______
),

[_SETTINGS] = LAYOUT(
    _______, HANDS,   QWERTY,  _______, _______, RESET,                       RESET,   _______, _______, QWERTY,  HANDS,   _______,
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______
),
};


// layer_state_t layer_state_set_user(layer_state_t state) {
//     state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
//     return state;
// }

// #ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     // Encoder on master side
//     if (index == 0) {
//         switch (get_highest_layer(layer_state)) {
//             // If the Default (QWERTY) layer is active
//             case _QWERTY:
//                 // Arrow Up/Down
//                 if (clockwise) {
//                     tap_code(KC_DOWN);
//                 } else {
//                     tap_code(KC_UP);
//                 }
//                 break;
// 
//             // If the RAISE layer is active
//             case _RAISE:
//                 // Switch browser tabs
//                 if (clockwise) {
//                     tap_code16(LCTL(KC_TAB));
//                 } else {
//                     tap_code16(RCS(KC_TAB));
//                 }
//                 break;
//             // If the ADJUST layer is active
//             case _ADJUST:
//                 // RGB brightness up/down
//                 if (clockwise) {
//                     rgblight_decrease_val(); // tap_code(RGB_VAD);
//                 } else {
//                     rgblight_increase_val(); // tap_code(RGB_VAI);
//                 }
//                 break;
//         }
//     }
//     // Encoder on slave side
//     else if (index == 1) {
//         switch (get_highest_layer(layer_state)) {
//             // If the Default (QWERTY) layer is active
//             case _QWERTY:
//                 // Scroll by Word
//                 if (clockwise) {
//                     tap_code16(LCTL(KC_RGHT));
//                 } else {
//                     tap_code16(LCTL(KC_LEFT));
//                 }
//                 break;
// 
//             // If the LOWER layer is active
//             case _LOWER:
//                 // Volume up/down
//                 if (clockwise) {
//                     tap_code(KC_VOLU);
//                 } else {
//                     tap_code(KC_VOLD);
//                 }
//                 break;
// 
//             // If the ADJUST layer is active
//             case _ADJUST:
//                 // RGB hue up/down
//                 if (clockwise) {
//                     // tap_code(RGB_HUI);
//                     rgblight_increase_hue();
//                 } else {
//                     // tap_code(RGB_HUD);
//                     rgblight_decrease_hue();
//                 }
//                 break;
//         }
//     }
//     return true;
// }
// #endif // ENCODER_ENABLE
