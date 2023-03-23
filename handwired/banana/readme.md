# Handwired Banana Macropad

This firmware is for a handwired Banana Macropad using an Arduino Pro Micro.

Keyboard Maintainer: [Hannes](https://github.com/HannesHasselbring/qmk_firmware)  
Hardware Supported: Arduino Pro Micro

![Banana image](https://i.imgur.com/2F6gi57.jpg)

## Pinout

The following pins are used:

- Columns 1-8: D1, D0, D4, C6, D7, E6, B4, B5
- Rows 1: B2
- Encoder Pad A: F5 (Optional)
- Encoder Pad B: F6 (Optional)

## Compiling and loading the firmware

Make example for this keyboard (after setting up your build environment):

```sh
qmk compile -kb handwired/banana -km via
```

To flash the firmware onto the microcontroller, use [qmk toolbox](https://github.com/qmk/qmk_toolbox)

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
