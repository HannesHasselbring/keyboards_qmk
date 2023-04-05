// Copyright 2021 @hanneshasselbring
// SPDX-License-Identifier: GPL-2.0+
#include "quantum/keycodes.h"

enum layer_names {
  _BSE,
  _LWR,
  _RSE,
  _ADJ
};

#define LOWER  MO(_LWR)
#define RAISE  MO(_RSE)

#define CT_Q  LCTL_T(KC_Q)
#define CT_CM RCTL_T(KC_COMM)
#define SF_Z  LSFT_T(KC_Z)
#define SF_ESC LSFT_T(KC_ESC)
#define SF_F11 LSFT_T(KC_F11)
#define SF_SS RSFT_T(KC_SLSH)
#define AL_X  LALT_T(KC_X)
#define AL_DT RALT_T(KC_DOT)
#define RA_SP LT(RAISE, KC_SPC)
#define LO_EN LT(LOWER, KC_ENTER)
#define LO_BSP LT(LOWER, KC_BSPC)
#define LO_SFT LT(LOWER, OSM(MOD_LSFT)) # todo: not working
#define WIN_SWT LGUI(KC_TAB)
#define IN_WIN_SWT LGUI(KC_GRV)
#define LALT_TAB LALT_T(KC_TAB)
#define LALT_BSPC LALT_T(KC_BSPC)
#define LGUI_ENT LGUI_T(KC_ENT)
#define LGUI_QUOT  LGUI_T(KC_QUOT)
#define SRN_SHT LSFT(LCTL(LGUI(KC_4))) //Shift-Command-4


// Tap hold macros
#define TH_M	LT(0,KC_M)
#define TH_COMM	LT(0,KC_COMM)
#define TH_DOT	LT(0,KC_DOT)
#define TH_SLSH	LT(0,KC_SLSH)
#define TH(k1,k2,k3,k4) LT(0,k1),LT(0,k2),LT(0,k3),LT(0,k4)

// Mod tap macros
#define HM_A	LSFT_T(KC_A)
#define HM_S	LALT_T(KC_S)
#define HM_D	LCTL_T(KC_D)
#define HM_F	LGUI_T(KC_F)
#define HM_J	RGUI_T(KC_J)
#define HM_K	RCTL_T(KC_K)
#define HM_L	RALT_T(KC_L)
#define HM_QUOT	RSFT_T(KC_QUOT)
#define HRML(k1,k2,k3,k4) LSFT_T(k1),LALT_T(k2),LCTL_T(k3),LGUI_T(k4)
#define HRMR(k1,k2,k3,k4) RGUI_T(k1),RCTL_T(k2),RALT_T(k3),RSFT_T(k4)


#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


// Default 3x5_2 split layout
#define _BASE \
    _________________COLEMAK_L1________________,          _________________COLEMAK_R1________________, \
    _________________COLEMAK_L2________________,          _________________COLEMAK_R2________________,  \
    _________________COLEMAK_L3________________,          _________________COLEMAK_R3________________,  \
                      LGUI_QUOT,  LO_EN,          RA_SP,  LALT_BSPC

#define _LOWER \
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, \
    SF_ESC, KC_LCTL,  KC_LALT, KC_LGUI, KC_QUOT,       KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_BSPC, \
                               _______, _______,       _______, OSM(MOD_LCTL)

#define _RAISE \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,       LGUI(KC_GRV), XXXXXXX, KC_GRV,  KC_TILD, KC_COLN, \
    SF_ESC, KC_RCTL,  KC_RALT, KC_RGUI, KC_DQUO,       KC_TAB,  XXXXXXX, KC_RCTL, KC_RALT, KC_ENTER, \
                               OSM(MOD_LCTL), _______,       _______, _______
    
#define _ADJUST \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG, \
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, XXXXXXX, \
    SF_F11,  KC_F12,  XXXXXXX, XXXXXXX, SRN_SHT,       WIN_SWT, IN_WIN_SWT, XXXXXXX, QK_REBOOT, MAGIC_TOGGLE_CTL_GUI, \
                               _______, _______,       _______, _______


// Mod-tap wrapper
#define HRM(k) HR_MODTAP(k)
#define HR_MODTAP( \
	  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	  l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	  l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                 l16, l17,   r16, r17                 \
) \
	  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05,       \
HRML(l06, l07, l08, l09), l10, r06, HRMR(r07, r08, r09, r10), \
	  l11, l12, l13, l14, l15,   r11,   r12, r13, r14, r15, \
	                 l16, l17,   r16, r17



// Layout aliases for json keymap
#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_r41_w(...) LAYOUT(__VA_ARGS__)



// Convert 3x5_2 to 41-key
#define C_41(k) CONV_41(k)
#define CONV_41( \
	     l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	     l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	     l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                    l16, l17,   r16, r17                 \
) \
KC_TAB,  l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, KC_BSPC, \
QK_GESC, l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, KC_SCLN, \
KC_LSFT, l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, KC_ENT,  \
	    l16, l17,  KC_SPC, r16, r17

