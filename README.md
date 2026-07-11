# Fundamentals of Computing — CSE 20311 (Notre Dame, Fall 2024)

Lab projects from my first-semester C course. Everything here is my own code, published after the course concluded.

| Lab | What it is |
|---|---|
| lab11 | **Snake** — final project: growing-snake arcade game on the course X11 gfx library (arrow-key controls, collision, score) |
| lab7 | **Conway's Game of Life** — file-loaded scenes, generation stepping |
| lab10 | **Fractals** — recursive fractal renderer (X11 gfx) |
| lab9 | Bouncing-ball + freeform animations |
| lab6 | US states data explorer + shortest-path over point sets (CSV parsing) |
| lab5 | Letter-frequency analysis of Shakespeare; random saying picker |
| lab4 | Grade stats, primes, ND football data crunching |
| lab2-3 | Mortgage tables, function graphing, quadratic solver, polar plots |
| lab1 | First programs |

The crossword generator from lab8 lives in its own repo: [crossword-generator](https://github.com/sviatil0/crossword-generator).

Build any gfx lab with its `Makefile` (requires X11).

## Demos

### Conway's Game of Life (lab7)

`./playlife myscene.txt` steps a 40x40 board; a mid-simulation generation:

```
┌----------------------------------------┐
|                                        |
|  XX                                    |
|  XX                                    |
|                                        |
|                                        |
|                                        |
|                                        |
|                                        |
|           X                            |
|           X                            |
|           X                            |
|                                        |
|                                        |
|                                        |
|                                        |
|                                        |
|                                        |
|                                        |
|                                        |
|                                        |
|                                        |
|       XXX X                            |
|       XXXXX                            |
|      XXX  X                            |
|         XX   X        X X              |
|         XX   X         XX              |
|      XXXXX   X         X               |
|       X                      XXX       |
|       X  XXX                           |
|                            X     X     |
|                            X     X     |
|                            X     X     |
|                                        |
|                              XXX       |
|                                        |
└----------------------------------------┘
```

Blocks are still lifes, the vertical bar is a blinker mid-cycle; scenes load from text files (`glider.txt`, `myscene.txt`) or interactive cell entry.

### Snake (lab11 final project)

X11 arcade game on the course gfx library: arrow keys steer, the snake grows on every apple, and the game speeds up as your score climbs. Build with `make` inside `lab11/` (requires X11) and run `./project`.
