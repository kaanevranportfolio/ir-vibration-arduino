# ir-vibration-arduino

Arduino (ATmega328) firmware built with PlatformIO. It has two separate programs, each with its own build environment.

| Environment | Board | What it does |
|---|---|---|
| `nanoatmega328` | Arduino Nano | Board bring-up: blinks the onboard LED (D13) without blocking, using `millis()` |
| `flame_detector` | Pro Mini 16 MHz | Reads an IR flame sensor and reports it on an LED and over serial |

## Flame detector

Wiring:

| Sensor / part | Pro Mini pin |
|---|---|
| Flame sensor DO (digital out) | D2 (internal pull-up, low = flame) |
| Indicator LED | D7 |

Every 500 ms it prints `FLAME DETECTED` or `NO FLAME` at 9600 baud and turns the LED on while a flame is detected. It doesn't use `delay()`, so the loop never blocks.

## Build and flash

Requires [PlatformIO](https://platformio.org/). Both environments upload on COM3.

```bash
pio run -e nanoatmega328 -t upload     # Nano blink
pio run -e flame_detector -t upload    # Pro Mini flame detector
pio device monitor -b 9600             # flame detector output
```

Each environment uses `build_src_filter` so it compiles only its own `main.cpp`. That lets both programs live in one project without their `setup()`/`loop()` functions clashing.
