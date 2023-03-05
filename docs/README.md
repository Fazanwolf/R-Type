# R-Type

R-Type is a 2D space shooter game. The goal is to destroy all the enemies and bosses to win the game.

## Description

R-Type is a 2D space shooter game. The goal is to destroy all the enemies and bosses to win the game. The player can move in all directions and shoot in all directions. The player can also use a special weapon to destroy all the enemies on the screen. The player can also use a shield to protect himself from the enemies' bullets. The player can also use a special weapon to destroy all the enemies on the screen. The player can also use a shield to protect himself from the enemies' bullets.

Particularities:
* Multiplayer: up to 4 player
* ...

## Getting Started

### Dependencies

Languages:
* [C++17](https://en.cppreference.com/w/cpp/17) - C++17 is the latest version of the C++ programming language, standardized by the International Organization for Standardization (ISO) in 2017.

Libraries:
* [SFML](https://www.sfml-dev.org/) - Simple and Fast Multimedia Library is a cross-platform multimedia library designed to provide a simple application programming interface (API) to various components of your PC, to ease the development of games and multimedia applications.
* [Skaldi](https://github.com/Fazanwolf/Skaldi) - Skaldi is a simple C++ library to handle TCP & UDP networking.

Tools:
* [Git](https://git-scm.com/) - Git is a free and open source distributed version control system designed to handle everything from small to very large projects with speed and efficiency.
* [CMake](https://cmake.org/) - CMake is an open-source, cross-platform family of tools designed to build, test and package software.
* [Doxygen](https://www.doxygen.nl/index.html) - Doxygen is a documentation system for C++, C, Java, Objective-C, Python, IDL (Corba, Microsoft, and UNO/OpenOffice flavors), Fortran, VHDL, PHP, C#, and to some extent D.
* [Docker](https://www.docker.com/) - Docker is a set of platform as a service (PaaS) products that use OS-level virtualization to deliver software in packages called containers.

### Building

#### Manually

```bash
cmake -B build -S .
cmake --build build --config Release
```

#### With docker

```bash
# Building the image
docker build -t rtype-image .
# Running the container
docker run -it --rm --name rtype rtype-image
```

### Executing program

...

## Help

If you have any questions, feel free open an issue on the [GitHub repository](https://github.com/Fazanwolf/Skaldi/issues)

## Contributors

* [Fazanwolf](https://github.com/Fazanwolf)
* [Pierre Cardia](https://github.com/gost-byte)
* [JonathanALBC](https://github.com/JonathanALBC)
* [KnightFaith](https://github.com/KnightFaith)
* [Théo TURPIN](https://github.com/theotrp)
* [Yannjoubert](https://github.com/Yannjoubert)

## License

This project is licensed under the [MIT License](https://github.com/Fazanwolf/R-Type/blob/main/LICENSE) - see the LICENSE file for details.
