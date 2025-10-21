# M5Stack Core2 LED Blink Application

**English | [日本語](README.md)**

A simple LED blink application for M5Stack Core2.

## Features

- Blink built-in LED (GPIO10) at 500ms intervals
- Display LED status (ON/OFF) on screen
- Output LED status to serial monitor

## Requirements

- M5Stack Core2 device
- PlatformIO (VSCode extension or CLI)
- USB cable (Type-C)

## Setup

### 1. Install PlatformIO

#### As VSCode Extension
1. Open VSCode
2. Open Extensions panel (Ctrl+Shift+X)
3. Search for "PlatformIO IDE" and install

#### As CLI
```bash
pip install platformio
```

### 2. Build Project

```bash
# Navigate to project directory
cd claude-code-web

# Install dependencies and build
pio run
```

### 3. Upload to M5Stack Core2

```bash
# Connect device and upload
pio run --target upload
```

### 4. Monitor with Serial Monitor

```bash
# Open serial monitor
pio device monitor
```

## Project Structure

```
claude-code-web/
├── src/
│   └── main.cpp          # Main program
├── platformio.ini        # PlatformIO configuration
├── README.md            # Japanese version
└── README_EN.md         # English version
```

## Code Explanation

### main.cpp

- `setup()`: Initialize M5Stack Core2 and LED pin, display initial screen
- `loop()`: Toggle LED state every 500ms, update display and serial output

## Customization

### Change Blink Interval

Modify the following line in `src/main.cpp`:

```cpp
const long interval = 500; // Milliseconds (500 = 0.5 seconds)
```

### Change LED Pin

The built-in LED on M5Stack Core2 is connected to GPIO10. To use a different pin, modify:

```cpp
pinMode(GPIO_NUM_10, OUTPUT); // Change GPIO_NUM_10 to any pin number
```

## Troubleshooting

### Device Not Recognized

1. Verify USB cable supports data transfer
2. Check if drivers are correctly installed (CP210x driver)
3. Verify device is properly connected

### Build Errors

```bash
# Reinstall platform and libraries
pio pkg uninstall
pio run
```

## License

This project is released under the MIT License.

## Author

Generated with Claude Code
