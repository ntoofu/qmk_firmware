#include QMK_KEYBOARD_H

#define _BASE_LAYER 0
#define _SYM_LAYER 1
#define _NUM_LAYER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_tectonics(
        /* LEFT */
        KC_NO  , KC_Q , KC_W , KC_E , KC_R , KC_T ,
        KC_ESC , KC_A , KC_S , KC_D , KC_F , KC_G ,
        KC_TAB , KC_Z , KC_X , KC_C , KC_V , KC_B ,
        /* RIGHT */
        KC_Y , KC_U , KC_I   , KC_O     , KC_P     , KC_NO     ,
        KC_H , KC_J , KC_K   , KC_L     , KC_ENTER , KC_BSPACE ,
        KC_N , KC_M , KC_SPC , KC_COMMA , KC_DOT   , KC_ENTER
    ),
    /*
         ! @ # $ %   ^ & * + |
       ' " { [ ( <   > ) ] } : ;
         ~ - = _ `   \ / ? , .
     */
    [_SYM_LAYER] = LAYOUT_tectonics(
        /* LEFT */
        KC_NO    , LSFT(KC_1)     , LSFT(KC_2)        , LSFT(KC_3)  , LSFT(KC_4)     , LSFT(KC_5)     ,
        RESET    , LSFT(KC_QUOTE) , LSFT(KC_LBRACKET) , KC_LBRACKET , LSFT(KC_9)     , LSFT(KC_COMMA) ,
        KC_QUOTE , LSFT(KC_GRAVE) , KC_MINUS          , KC_EQUAL    , LSFT(KC_MINUS) , KC_GRAVE       ,
        /* RIGHT */
        LSFT(KC_6)   , LSFT(KC_7) , LSFT(KC_8)     , LSFT(KC_EQUAL)    , LSFT(KC_BSLASH) , KC_NO ,
        LSFT(KC_DOT) , LSFT(KC_0) , KC_RBRACKET    , LSFT(KC_RBRACKET) , LSFT(KC_SCOLON) , KC_DELETE ,
        KC_BSLASH    , KC_SLASH   , LSFT(KC_SLASH) , KC_COMMA          , KC_DOT          , KC_SCOLON
    ),
    [_NUM_LAYER] = LAYOUT_tectonics(
        /* LEFT */
        KC_NO    , KC_F2         , KC_F3   , KC_F4   , KC_F5     , KC_F6   ,
        KC_F1    , KC_SCROLLLOCK , KC_HOME , KC_PGUP , KC_PGDOWN , KC_END  ,
        KC_PAUSE , KC_1          , KC_2    , KC_3    , KC_4      , KC_5    ,
        /* RIGHT */
        KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11    , KC_NO      ,
        KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_INSERT , KC_F12     ,
        KC_6    , KC_7    , KC_8    , KC_9     , KC_0      , KC_PSCREEN
    ),
};
