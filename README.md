Project Overview
- TrinityLED is an Arduino/ESP32/PlatformIO library for driving addressable LED installations.
- Previously, the Trinity Codebase was designed to drive a Nanoleaf knockoff as my second embedded systems school project ever. It has since been periodically updated and adapted for various LED projects.
- Every project required some custom refactioring. Eventually, all the different copies and implementations were no longer manageable, so I started refactoring the common functionality into this library.


Project Metadata
- Type: Firmware / Arduino library
- Client: Many: Personal projects, client projects (GLOW Einhoven 2024, FutureMindz Westpoint, Doom Slayer, CarJack).
- Status: Refactor into Library WIP
- Product: TrinityLED (library + example sketches)
- Confidentiality: No NDA known; repository intended for local use or portfolio review


Technical Stack
- Programming language(s): C++ (Arduino-style / PlatformIO project)
- Hardware / platform: Arduino-compatible microcontrollers (target configurable in `platformio.ini`; common targets include AVR, ESP8266, ESP32)
- Tools & build system: PlatformIO (CLI or VSCode PlatformIO extension)
- Communication protocols / interfaces (if applicable): GPIO, digital inputs (buttons), analog inputs (light sensor), FastLED for WS28XX/NEOPIXEL chains


System Description
- Github Structure:
    - Branch "main": The classic codebase before adapting into a library. Acts much like a library but with less modularity and more hardcoded project-specific logic.
    - Branch "libraryFying": The refactored library version (WIP). This is the intended long-term structure for the codebase.
    - Branch "Webserver-update": Old attempts at adding webserver functionality to control effects (ESP32/ESP8266 only). Not currently maintained.
    - Branches "HouseCube", "EyeOfTheStorm", "Atos", "PraetorTemp", "Westpoint": Project-specific forks of the codebase for various LED installations. These branches contain custom logic and configurations for specific projects, intended to be replaced by examples in the library version.
- High-level architecture: The library provides a core LED management system, with additional modules for communications and input handling.
- The codebase is organized into small, focused modules (drivers and managers) compiled into a single firmware image. Initialization happens in the main sketch; runtime is cooperative and module-driven: inputs are sampled, effects are processed, and LED buffers are updated via FastLED.
- Main LED handling components, tasks, or modules:
  - `TrinityLED.cpp` / `TrinityLED.h`: Core LED management and top-level helpers
  - `effectProcessor/`: Effect scheduling and effect implementations
  - `MaskManager/`: (WIP) Mask effects and coordinate mapping utilities for panels 
  - `Panel/`, `Diode/`: Panel and diode grouping/abstractions
- Additional helper modules:
  - `AskButton/`, `LightSensor/`: Input handling for buttons and light sensor
  - `Comms/`: Communication helpers (project-specific transmission types)
  - `SleepTimer/`: Low-power / sleep helper logic
- Example sketches and usage:
  - `examples/`: Example sketches demonstrating library usage and wiring. These sketches are modified versions of the old implementations of the codebase before adapting into a library.


Current State
- Disclaimer: The codebase has not been maintained for about 2 years; I have to be honest when I say I am not certain of the exact current state without testing. For this reason, I will refer to this project historically, and will refer to features that have functioned in the past, which I intend to keep. 
- What is working:
    - Core LED driving functionality via FastLED
    - Grouping LEDs into "panels"
    - Basic effect processing and scheduling (Effects, delays, speeds, custom colours, etc)
    - Input handling (buttons, light sensor)
- What is not working / missing:
    - The `MaskManager` module is a work-in-progress and is not yet functional. It is intended to provide coordinate-based mapping and masking to edit panels and their LED's as if the system is a 2D canvas.
    - I have the intention to make this code public, requiring me to clean up and document the codebase.


Key Technical Challenges 
- Keeping the led effects synchronised with all other leds running different effects.
- Keeping CPU and memory usage low to allow tiny boards such as an Arduino Uno to run moderate LED counts (50-100 LEDs).
- Providing many flexible effects (Blink, Rainbow, Breathing, flashing), all with adjustable speed, offset and colour parameters.
- Providing control over individual leds, panels, groups of panels, and the entire installation, all simultaneously.
- Maintaining a codebase written in my first year of embedded systems education.
- Currently: porting the many different copies of said codebase into a reusable library with clean APIs and modular structure.

Installation Instructions

Future Improvements
- Check functionality of the codebase on supported hardware.
- Complete the `MaskManager` module to provide 2D coordinate mapping and masking functionality. This will allow effects to be applied to specific shapes or areas of the LED installation.
- Port more example sketches demonstrating various use cases and configurations.


Disclaimer
- This Readme file has been generated by an AI language model (ChatGPT) based on the provided code context.
- I have only quickly reviewed and edited the content for accuracy.
