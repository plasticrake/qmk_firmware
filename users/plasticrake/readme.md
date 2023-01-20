# plasticrake's QMK Userspace

## Overview

The "smallest" keyboards I use are 65%. I try not to be too clever with my
layers; as I like to keep good muscle memory for "standard" keyboards or laptop
keyboards. I do like RGB keys, but I like them to be utilized practically and
not for "looks". And I wanted to find a good balance of features.

The code in this userspace is designed to be very modular. Modular code also
means that it should be easy to identify and adapt specific pieces to your own firmware.

### Keyboards and Keymaps

The following keyboards use the files in this userspace:

-   [GMMK Pro](../../keyboards/gmmk/pro/rev1/ansi/keymaps/plasticrake/readme.md)

## Features

-   **[Caps Word](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_caps_word.md)**,
    `CAPS_WORD_ENABLE` and `BOTH_SHIFTS_TURNS_ON_CAPS_WORD` are on by default.
-   **Mouse jiggler**, adapted from [replicaJunction](https://github.com/qmk/qmk_firmware/blob/master/users/replicaJunction/readme.md)
-   **Secrets**, adapted from [replicaJunction](https://github.com/qmk/qmk_firmware/blob/master/users/replicaJunction/readme.md)
    and [Drashna](https://github.com/qmk/qmk_firmware/blob/master/users/drashna/keyrecords/secrets.md)

### Mouse Jiggler

This adds a keycode that will move the mouse cursor on each matrix scan. Used to
prevent the screen from locking if you're temporarily doing something else
(working on a different machine, reading/writing, etc.).

Settings for `rules.mk` (with defaults):

-   `USER_MOUSE_JIGGLE_ENABLE`, set to `yes` to enable
-   `USER_MOUSE_JIGGLE_OUTPUT = no`
-   `USER_MOUSE_JIGGLE_RGB_MATRIX_MODE = RGB_MATRIX_BAND_VAL`

If `USER_MOUSE_JIGGLE_OUTPUT` is set to yes, when you press the keycode, the
keyboard will optionally write the text "Mouse jiggler enabled" to signify
that the behavior is active. I suggest opening a Notepad window before pressing
the key.

If `USER_MOUSE_JIGGLE_RGB_MATRIX_MODE` is set to an [`rgb_matrix_effect`](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#rgb-matrix-effects-idrgb-matrix-effects)
setting, it will be activated while the jiggler is enabled.

Pressing any key will automatically disable the feature again. This is because
it causes a huge hit to the reliability and performance of the keyboard while
it's active (adding stuff to every matrix scan will do that). I kept forgetting
to turn it off before trying to use the keyboard again, so I decided to make it
automatically disable itself.

The feature also depends on the Mouse Keys feature, so ensure you don't disable
`MOUSEKEY_ENABLE`.

### Secrets

This implementation of the "secrets" concept is nearly identical to `replicaJunction`
which was based on `Drashna`'s. The only thing missing is a file called
`secret_definitions.h`, which contains the actual text contained in those macros.

Settings for `rules.mk` (with defaults):

-   `USER_SECRETS_ENABLE`, set to `yes` to enable

To use my implementation, create a file of that name in the same directory. Make
sure you've got a `.gitignore` file in place, and add these contents to the
definitions file:

```c
#pragma once
static const char * const secrets[] = {
  "secret1",
  "secret2",
  "secret3",
  "secret4",
  "secret5"
}
```

Change the quoted text to the text you'd like and you're golden. If you need
more (or fewer) items, you'll probably need to adjust the code in `secrets.c`
as well, since it looks for up to five items in a switch case.

## Credits

[replicaJunction](https://github.com/qmk/qmk_firmware/blob/master/users/replicaJunction/readme.md)

[Drashna](https://github.com/qmk/qmk_firmware/blob/master/users/drashna/readme.md)

## License

Copyright 2023 D Patrick Seal (@plasticrake)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
