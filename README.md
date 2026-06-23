# Chess (Development)

A chess game written in C using Raylib.

This project was created as a way to study board game logic, movement validation and software organization while implementing the rules of chess from scratch.

The current version is still under development and focuses on core gameplay mechanics and rule implementation.

## Project Goals

The primary objective of this project is to understand how turn-based games are structured internally and how classic chess rules can be implemented using low-level programming concepts.

Technical goals include:

* Implementing chess rules from scratch.
* Practicing software architecture in C.
* Studying board representation techniques.
* Improving understanding of pointers and memory management.
* Learning game state management.
* Implementing movement validation algorithms.
* Studying game logic and rule enforcement.
* Experimenting with collision detection and user interaction.
* Practicing texture management using Raylib.

## Current Features

* Graphical chess board.
* Complete board initialization.
* Piece rendering using textures.
* Piece selection using the mouse.
* Basic piece movement.
* Individual movement generation for:

  * Pawn
  * Bishop
  * Knight
  * Rook
  * Queen
  * King
* Turn state structure.
* Initial check and checkmate detection experiments.

## Technologies

* C
* Raylib
* GCC
* Makefile

## Development Environment

The project is currently developed and tested on Windows.

## Project Structure

```text
src/
├── cell.c
├── piece.c

src_game/
├── setup.c
├── draw.c
├── update.c

src_pieces/
├── pieces_rules.c

util/
├── util.c

include/
├── chess.h
```

## Build

Requirements:

* GCC
* Raylib

Compile using:

```bash
make
```

## Current State

**Status:** Prototype / Early Development

The project is currently focused on implementing and validating chess rules before introducing more advanced gameplay constraints.

Several mechanics are still experimental and may change during development.

## Planned Features

* Legal move validation.
* Full turn management.
* Check enforcement.
* Complete checkmate detection.
* Stalemate detection.
* Castling.
* En passant.
* Pawn promotion.
* Capturing system.
* Piece removal.
* Move history.
* Board highlighting for possible moves.
* Game restart system.
* Basic UI improvements.

## Motivation

Chess provides an excellent environment for studying algorithms, state machines and game logic. Every rule introduces new programming challenges, making it a valuable project for improving problem-solving skills and software design.

The long-term goal is to create a fully playable chess game while deepening knowledge of game development in C.
