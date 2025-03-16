# RPG Game (SFML and C++).

## Overview
This is a simple RPG game built using **C++** and **SFML**. The game includes a player character, enemies, projectiles, and collision detection. It features smooth animations, player movement, and combat mechanics.

## Features
- **Player Character**: Move using WASD keys, attack with the mouse.
- **Enemies**: Basic AI that interacts with the player.
- **Projectile System**: Fire arrows at enemies.
- **Collision Detection**: Player and enemies interact physically.
- **Frame Rate Display**: Shows FPS and frame timing.

## Technologies Used
- **C++17**
- **SFML 2.5** (System, Window, Graphics, Network, Audio)
- **CMake** for project build management

## File Structure
```
/project-folder
│── CMakeLists.txt         # Build configuration
│── main.cpp               # Entry point of the game
│── Player.h / Player.cpp  # Player class (movement, health, attack)
│── Enemy.h / Enemy.cpp    # Enemy class (AI, attack, health)
│── Math.h / Math.cpp      # Math utilities (vector normalization, collision)
│── Weapon.h / Weapon.cpp  # Arrow/projectile mechanics
│── Framerate.h / Framerate.cpp # FPS display system
│── Assets/
│   ├── Fonts/
│   │   ├── GothamRounded.otf   # Game font
│   ├── Sprites/
│   │   ├── BODY_human.png      # Player sprite
│   │   ├── BODY_skeleton.png   # Enemy sprite
│   │   ├── WEAPON_arrow.png    # Arrow sprite
```

## Installation & Setup
### Prerequisites
- **C++ Compiler** (GCC/Clang/MSVC with C++17 support)
- **SFML 2.5** installed
- **CMake 3.10+**

### Build Instructions
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/RPG-SFML.git
   cd RPG-SFML
   ```
2. Create a `build` directory and navigate to it:
   ```sh
   mkdir build && cd build
   ```
3. Run CMake to generate build files:
   ```sh
   cmake ..
   ```
4. Compile the project:
   ```sh
   make
   ```
5. Run the game:
   ```sh
   ./RPG
   ```

## Controls
- **W, A, S, D** → Move Player
- **Mouse Click** → Attack (fire arrows)

## Future Enhancements
- **Improved AI** for enemies
- **Health and XP system** for progression
- **Inventory system** for weapons and items

## License
This project is open-source. Feel free to contribute and improve!

---
Made with ❤️ using C++ & SFML.

