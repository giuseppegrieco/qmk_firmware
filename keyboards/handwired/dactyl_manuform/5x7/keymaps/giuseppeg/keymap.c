#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMBOLS 1

// Some basic macros
#define TASK LCTL(LSFT(KC_ESC))
#define TAB_R LCTL(KC_TAB)
#define TAB_L LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ESC  |   1  |   2  |   3  |   4  |   5  | PGUP |           | PGDN |   6  |   7  |   8  |  9   |   0  |  PSCR  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   TAB  |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
     * |  CTRL  |   A  |   S  |   D  | F:ALT|G:CTRL| TRO  |           | DEL  |   H  |   J  |   K  |   L  |  ;   |   '    |
     * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
     * |  SHIFT |   Z  |   X  |   C  |   V  |   B  |                         |N:SUPR|   M  |   ,  |   .  |  /   | SHIFT  |
     * `--------+------+------+------+------+-------                         -------+------+------+------+------+--------'
     *    | CAPS | SUPR | C/PUP | C/PDW |                                              | LEFT |  UP  | DOWN  | RIGHT  |
     *    `-----------------------------'                                              `------------------------------'
     *
     *                                .--------------------.         .---------------.------.
     *                                |   [  |      |      |         |        |      |  ]   |
     *                                |------|  SPC | BSPC |         |   TAB  | ENTR |------|
     *                                | SYM  |      |      |         |        |      |  ESC |
     *                                '------|-------------|         |---------------'------'
     *                                       | UP   | DOWN |         |  LEFT  | RGHT |
     *                                       '------'------'         '--------'------'
     */
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_PGUP, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_LCTL, KC_A, KC_S, KC_D, MT(MOD_LALT, KC_F), MT(MOD_LCTL, KC_G), TAB_RO, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_CAPS, KC_LGUI, TAB_L, TAB_R, TT(_SYMBOLS), KC_LBRC, KC_UP, KC_SPC, KC_DOWN, KC_BSPC,
        // right hand
        KC_PGDN, KC_6, KC_7, KC_8, KC_9, KC_0, KC_PSCR, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_DEL, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, MT(MOD_RGUI, KC_N), KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RBRC, KC_ESC, KC_ENT, KC_RGHT, KC_TAB, KC_LEFT),

    /*
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | QK_BOOT|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  VOLU  |   %  |   ,  |   [  |  ]   |   ?  |  ;   |           |  :   |  \   |   7  |   8  |   9  |  *   |        |
     * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
     * |  VOLD  |   |  |   =  |   (  |  )   |   <  |  >   |           |  &   |  `   |   4  |   5  |   6  |  +   |        |
     * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
     * |  MUTE  |   #  |   _  |   {  |  }   |   ^  |                         |  ~   |   1  |   2  |   3  |  \   |        |
     * `--------+------+------+------+------+-------                         -------+------+------+------+------+--------'
     *    | MPRV |  @   |       | MSTP  |                                              | MPLY |      |   0   | MNXT   |
     *    `-----------------------------'                                              `------------------------------'
     *
     *                                .--------------------.         .---------------.------.
     *                                |      |      |      |         |        |      |      |
     *                                |------|      |      |         |   '    |  -   |------|
     *                                | SYM  |      |      |         |        |      |      |
     *                                '------|-------------|         |---------------'------'
     *                                       |      |      |         |   !    |   "  |
     *                                       '------'------'         '--------'------'
     */
    [_SYMBOLS] = LAYOUT_5x7(
        // left hand
        QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_VOLU, KC_PERC, KC_COMM, KC_LBRC, KC_RBRC, KC_QUES, KC_SCLN, KC_VOLD, KC_PIPE, KC_EQL, KC_LPRN, KC_RPRN, KC_LT, KC_GT, KC_MUTE, KC_HASH, KC_UNDS, KC_LCBR, KC_RCBR, KC_CIRC, KC_MPRV, KC_AT, _______, KC_MSTP, TT(_SYMBOLS), _______, _______, _______, _______, _______,
        // right hand
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_COLN, KC_BSLS, KC_7, KC_8, KC_9, KC_ASTR, _______, KC_AMPR, KC_GRV, KC_4, KC_5, KC_6, KC_PLUS, _______, KC_TILD, KC_1, KC_2, KC_3, KC_BSLS, _______, KC_MPLY, _______, KC_0, KC_MNXT, _______, _______, KC_MINS, KC_DQUO, KC_QUOT, KC_EXLM),
};
