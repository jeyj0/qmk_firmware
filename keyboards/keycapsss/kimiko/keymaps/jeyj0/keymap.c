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
    _HANDS_ON,
    _QWERTY,
    _NUM,
    _NAV,
    _MOUSE,
    _SETTINGS,
};

#define HANDS    DF(_HANDS_ON)
#define QWERTY   DF(_QWERTY)
#define NUM_SPC  LT(_NUM, KC_SPC)
#define NUM_E    LT(_NUM, KC_E)
#define NUM_KC0  LT(_NUM, KC_0)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define NAV_ENT  LT(_NAV, KC_ENT)
#define LT_SETT  LT(_SETTINGS, _______)
#define MSE_AGR  LT(_MOUSE, KC_RALT)

#define SFT_KCF  LSFT_T(KC_F)
#define SFT_KCJ  RSFT_T(KC_J)
#define SFT_KCT  LSFT_T(KC_T)
#define SFT_KCA  RSFT_T(KC_A)
#define SFT_RPRN LSFT_T(KC_RPRN)
#define SFT_KC4  LSFT_T(KC_4)
#define SFT_RGHT LSFT_T(KC_RGHT)
#define SFT_LEFT LSFT_T(KC_LEFT)

enum custom_keycodes {
    COM_QUS,
    DOT_EXC,
    SLS_BSL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool isShifted = false;
    if (record->event.pressed) {
        isShifted = get_mods() & MOD_MASK_SHIFT;
    }
    switch (keycode) {
        case COM_QUS: {
            static uint8_t kc;
            if (record->event.pressed) {
                if (isShifted) {
                    kc = KC_SLASH;
                } else {
                    kc = KC_COMM;
                }

                register_code(kc);
            } else {
                unregister_code(kc);
            }
            break;
        }
        case DOT_EXC: {
            static uint8_t kc;
            if (record->event.pressed) {
                if (isShifted) {
                    kc = KC_1;
                } else {
                    kc = KC_DOT;
                }

                register_code(kc);
            } else {
                unregister_code(kc);
            }
            break;
        }
        case SLS_BSL: {
            static uint8_t kc;
            if (record->event.pressed) {
                if (isShifted) {
                  del_mods(MOD_MASK_SHIFT);
                  kc = KC_BSLASH;
                } else {
                  kc = KC_SLASH;
                }

                register_code(kc);

                if (isShifted) {
                  register_code(KC_LSFT);
                }
            } else {
                unregister_code(kc);
            }
            break;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_HANDS_ON] = LAYOUT(
    KC_Q,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TAB,  KC_W,    KC_G,    KC_M,    KC_P,    KC_ESC,                      KC_QUOT, KC_U,    KC_K,    KC_J,    KC_SCLN, XXXXXXX,
    KC_Z,    KC_R,    KC_S,    KC_N,    SFT_KCT, KC_B,                        KC_Y,    SFT_KCA, KC_O,    KC_I,    KC_H,    KC_Q,
    KC_LCTL, KC_X,    KC_C,    KC_L,    KC_D,    KC_V,     KC_MUTE, KC_MUTE,  KC_MINS, KC_F,    COM_QUS, DOT_EXC, SLS_BSL, KC_RCTL,
                      KC_CAPS, KC_LALT, KC_LGUI, NUM_E,    NAV_BSPC,NAV_ENT,  NUM_SPC, MSE_AGR, KC_RGUI, KC_CAPS
),

[_QWERTY] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_ESC,  KC_A,    KC_S,    KC_D,    SFT_KCF, KC_G,                        KC_H,    SFT_KCJ, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_MUTE, KC_MUTE,  KC_N,    KC_M,    _______, _______, _______, _______,
                      _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______
),

[_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    _______, _______, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                     KC_AT,   KC_7,    KC_8,    KC_9,    _______, _______,
    _______, KC_HASH, KC_EQL,  KC_LPRN, KC_RPRN, KC_TILD,                     KC_CIRC, SFT_KC4, KC_5,    KC_6,    KC_DLR,  _______,
    _______, _______, KC_ASTR, KC_LT,   KC_GT,   KC_GRV,   _______, _______,  KC_AMPR, KC_1,    KC_2,    KC_3,    KC_PIPE, _______,
                      _______, _______, _______, _______,  _______, _______,  NUM_KC0, _______, _______, _______
),

[_NAV] = LAYOUT(
    LT_SETT, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, LT_SETT,
    _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______,                     _______, KC_PGDN, KC_UP,   KC_PGUP, _______, _______,
    _______, KC_HOME, KC_LEFT, KC_DOWN, SFT_RGHT,KC_END,                      KC_HOME, SFT_LEFT,KC_DOWN, KC_RGHT, KC_END,  _______,
    _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______
),

[_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_WH_U, KC_ACL2, _______,                     _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    _______, KC_WH_L, KC_WH_R, KC_WH_D, KC_ACL1, KC_BTN1,                     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, KC_ACL0, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
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


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // Encoder on master side
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case _HANDS_ON:
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC__VOLDOWN);
                } else {
                    tap_code(KC__VOLUP);
                }
                break;
        }
    }
    // Encoder on slave side
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _HANDS_ON:
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC__VOLUP);
                } else {
                    tap_code(KC__VOLDOWN);
                }
                break;
        }
    }
    return true;
}
#endif // ENCODER_ENABLE
