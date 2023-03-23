/* Copyright 2021 Hannes Hasselbring
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

#define _MAIN 0
#define _LOWER 1

// Intellij
//
// back
#define JBACK RALT(RCMD(KC_LEFT))
// intruduce constant
#define JCONST RALT(RCMD(KC_C))
// intruduce variable
#define JVAR RALT(RCMD(KC_V))
// extract method
#define JMETH RALT(RCMD(KC_M))
// inline
#define JINL RALT(RCMD(KC_N))
// file structure
#define JFILE LGUI(KC_F12)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Keymap __MAIN: Default Layer
	*  ,---------------------------------------------------.
	*  | |-----|-----|-----|-----|-----|-----|-----|-----| |
	*  | |  F1 |  F2 |  F3 |  F4 | F5  |  F6 |  F7 |Mute | |
	*  | |-----|-----|-----|-----|-----|-----|-----|-----| |
	*  '---------------------------------------------------'
	*/
  [_MAIN] = LAYOUT(
    LT(_LOWER, KC_F1),  KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_KB_MUTE
  ),
   [_LOWER] = LAYOUT(
    XXXXXXX,  JBACK, JVAR, JMETH, JINL, LGUI(KC_F12), KC_TRNS, QK_REBOOT
  ),
  [2] = LAYOUT(
    _______,  _______, _______, _______, _______, _______, _______, _______
  ),
  [3] = LAYOUT(
    _______,  _______, _______, _______, _______, _______, _______, _______
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_KB_VOLUME_UP);
        } else {
            tap_code(KC_KB_VOLUME_DOWN);
        }
    }
    return true;
}
