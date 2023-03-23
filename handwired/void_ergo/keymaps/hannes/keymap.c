/* Copyright 2020 Hannes Hasselbring
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


enum custom_keycodes {
    MAC_AE = SAFE_RANGE,
    MAC_OE,
    MAC_UE
};

// Layer
#define L3_SPC LT(3, KC_SPACE)
#define L3_ENT LT(3, KC_ENTER)

#define CTL_ESC CTL_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENTER)
#define CMD_LFT LCMD(KC_LEFT)
#define CMD_RGHT LCMD(KC_RIGHT)

// Home row mod
// see https://docs.qmk.fm/#/mod_tap
// https://precondition.github.io/home-row-mods#cags
// #define CTL_T(KC_A)
// #define MODA_S MT(KC_LALT, KC_S)
// #define MODG_D MT(KC_LGUI, KC_D)
// #define MODS_F MT(KC_LSFT, KC_F)

// #define MODS_J MT(KC_RSFT, KC_J)
// #define MODG_K MT(KC_RGUI, KC_K)
// #define MODA_L MT(KC_RALT, KC_L)
// #define MODC_SM MT(KC_RSFT, KC_SCLN)

// MacOS Screenshot
#define PSHOT LSFT(LCTL(LCMD(KC_4)))

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

// Hammerspoon/Shiftit
// Hold Left Control, Alt and GUI and press LEFT
#define WIN_LEFT LCAG(KC_LEFT)
#define WIN_RGHT LCAG(KC_RIGHT)
#define WIN_MAX LCAG(KC_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_void_ergo(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_ESC,CTL_T(KC_A),LOPT_T(KC_S),LGUI_T(KC_D),LSFT_T(KC_F),KC_G,              KC_H,RSFT_T(KC_J),RGUI_T(KC_K),ROPT_T(KC_L),RCTL_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SFT_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_COPY, KC_LGUI, MO(1),  L3_ENT, KC_LBRC,    KC_RBRC,  L3_SPC, MO(2), KC_RALT, KC_PSTE
                     //`-------------------------------------------'  `--------------------------------------------'

  ),

  [1] = LAYOUT_void_ergo(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                       _______, KC_LGUI,    MO(3),  KC_ENT,    RESET,    _______,  KC_SPC,   MO(3), KC_RALT, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_void_ergo(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,WIN_LEFT,WIN_RGHT, WIN_MAX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        _______, KC_LGUI, MO(3),  KC_ENT, _______,    _______,  KC_SPC, MO(3), KC_RALT, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_void_ergo(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, PSHOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          KC_F6,  MAC_UE,    KC_UP, MAC_OE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, MAC_AE, KC_LOPT, KC_LCMD, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX,  JCONST,    JVAR, XXXXXXX,                         JINL,   JMETH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        _______, KC_LGUI, _______,  KC_ENT,   RESET,      JBACK,  KC_SPC, _______, KC_RALT, _______
                                      //`--------------------------'  `--------------------------'
  )




};

//
// source: https://github.com/qmk/qmk_firmware/blob/master/keyboards/tada68/keymaps/mlechner/keymap.c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case MAC_UE:
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
          SEND_STRING(SS_LALT("u") SS_LSFT("u"));
        } else {
				  SEND_STRING(SS_LALT("u")"u");
        }
				return false;
      case MAC_AE:
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
				  SEND_STRING(SS_LALT("u") SS_LSFT("a"));
        } else {
          SEND_STRING(SS_LALT("u")"a");
        }
        return false;
      case MAC_OE:
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
          SEND_STRING(SS_LALT("u") SS_LSFT("o"));
        } else {
          SEND_STRING(SS_LALT("u")"o");
        }
        return false;
		}
	}
	return true;
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

/*
 * ROTARY ENCODER
 */

static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 750

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (IS_LAYER_ON(1)) {
      if (clockwise) {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }
        tap_code(KC_TAB);
      } else {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }

        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_UP);
      } else {
        tap_code(KC_DOWN);
      }
    }
  }
  else if (index == 1) {
    if (IS_LAYER_ON(2)) {
      if (clockwise) {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }
        tap_code(KC_TAB);
      } else {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }

        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    } else {
      if (clockwise) {
        tap_code(KC_RIGHT);
      } else {
        tap_code(KC_LEFT);
      }
    }
  }
}

void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LALT);
      tabbing = false;
    }
  }
}

void matrix_init_user(void) {

}
