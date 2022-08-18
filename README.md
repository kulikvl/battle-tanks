<p align="center">
  <img src="https://user-images.githubusercontent.com/111417661/185357562-63c60cc5-e7d5-43d6-9be9-c333c437b60d.gif" />
</p>

---

- [1. Introduction](#1-introduction)
- [2. Installation and usage](#2-installation-and-usage)
- [3. Code](#3-code)

## 1. Introduction

This is a 2D game written in C++ using the SDL 2.0 library.

> The idea was to make a game in the genre of *Tower Defense* and in the style of the good old pixel game "Battle city".

Your task is to hold out as long as possible.

## 2. Installation and usage

[1] Install the repository by forking it and then downloading it using:

```bash
git clone https://github.com/kulikvl/TowerDefense.git
```

[2] Dependancies: lSDL2, lSDL2_image. Install them if you don't have:

```bash
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
```
[3] That would build and run the game:

```bash
make run
```

## 3. Code

Things to pay attention to in the project:

* The code is very well documented
* C++17 and C++20 were prefered and widely used (minimum dangerous memory allocations)
* OOP is significantly used (inheritance and game design patterns)

