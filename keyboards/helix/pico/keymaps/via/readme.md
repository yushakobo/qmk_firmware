# The Default HelixPico Layout
## Layout

### Qwerty
```
 ,-----------------------------------------.             ,-----------------------------------------.
 | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 |Adjust| Esc  | Alt  | GUI  | EISU |Lower |Space |Space |Raise | KANA | Left | Down |  Up  |Right |
 `-------------------------------------------------------------------------------------------------'
```


## Layers

|Priority|number|name|description|
| ---- | ---- | --- | --- |
|high|16|Adjust|Functions|
||2|Raise|Numeric charactors|
||1|Lower|Other charactors|
|low|0|Qwerty|QWERTY leyout(base)|

### Lower
```
 ,-----------------------------------------.             ,-----------------------------------------.
 |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      | PrSc | Home | End  |      |
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 `-------------------------------------------------------------------------------------------------'
```

### Raise
```
 ,-----------------------------------------.             ,-----------------------------------------.
 |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      | PrSc |PageDn|PageUp|      |
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 `-------------------------------------------------------------------------------------------------'
```

### Adjust (Lower + Raise)
```
 ,-----------------------------------------.             ,-----------------------------------------.
 |      | Reset|      |      |      |      |             |      |      |      |      |      |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |Aud on|Audoff|MU TOG|MU MOD| Mac  |             | Win  |      |      |      |      |      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |CK TOG|CK RST| CK UP|CK DWN|      |             |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
 `-------------------------------------------------------------------------------------------------'
```

## Customize

see `qmk_firmware/keyboards/helix/pico/keymaps/default/rules.mk`

```
# Helix Spacific Build Options
# you can uncomment and edit follows 4 Variables
#  jp: 以下の4つの変数を必要に応じて編集し、コメントアウトをはずします。
# LED_BACK_ENABLE = no        # LED backlight (Enable WS2812 RGB underlight.)
# LED_UNDERGLOW_ENABLE = no   # LED underglow (Enable WS2812 RGB underlight.)
# LED_ANIMATIONS = yes        # LED animations
# IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
```
## Compile

go to qmk top directory.
```
$ cd qmk_firmware
```

build
```
$ make helix/pico:default
$ make helix/pico/back:default               # with backlight
$ make HELIX=no-ani helix/pico/back:default  # with backlight without animation
$ make helix/pico/under:default              # with underglow
```

build (experimental use of split_common with backlight)
```
$ make helix/pico/sc:default
```

flash to keyboard
```
$ make helix/pico:default:flash
$ make helix/pico/back:default:flash               # with backlight
$ make HELIX=no_ani helix/pico/back:default:flash  # with backlight without animation
$ make helix/pico/under:default:flash              # with underglow

```

## Link
* more detail wrote in Japanese [helix/Doc/firmware_jp.md](https://github.com/MakotoKurauchi/helix/blob/master/Doc/firmware_jp.md)
* [Helix top](https://github.com/MakotoKurauchi/helix)
