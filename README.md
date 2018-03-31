*README file for "Conway's Game of Life" project (C++ implementation)
Author: Seth Cattanach
CSE-20311 Fall 2017

------------------
Project Overview
------------------

"Conway's Game of Life" is a cellular automation in which a set of initial 
conditions is simulated over time under a specific set of rules. Each cell on 
a board is initially set as "alive" or "dead" and the following rules are 
applied during each iteration of the game. A "neighbor" is defined as one of 
eight cells directly adjacent to or diagonal to the cell in question.

1. Any "alive" cell with fewer than two "alive" neighbrs will become dead (by 
"underpopulation")

2. Any "alive" cell with more than three live neighbors will become dead (by 
"overcrowding")

3. Any "alive" cell with two or three neighbors will stay alive for the next 
round.

4. Any "dead" cell with exactly three neighbors will come to life for the 
next round.

Each subsequent round applies these rules to the current board of "alive" and 
"dead" cells, leading to a number of interesting patterns. 

For more information on Conway's Game of Life, visit "www.conwaylife.com"


-------------------
Usage/Instructions
-------------------

This implementation allows the user to simulate Conway's Game of Life in two 
modes: interactive mode and automatic mode. To enter interactive mode, simply 
run the provided executable with the command ./playlife

In interactive mode, the user can add a live cell by typing "a" followed by 
the coordinates of the target cell. For example: a 2 0

To remove a live cell, type "r" followed by the cell coordinates: r 2 0

To advance to the next round (one iteration), type "n"

To play the game continuously, type "p" (in this case, the user must 
force-quit the program)

To enter "automatic" mode, the user must specify a list of commands via input 
redirection from the command line. Some sample scenes are provided as text 
files: scene1.txt, scene2.txt, scene3.txt, etc. Each of these scenes yields a 
different starting configuration (still-lives, gliders, etc.)

To enter automatic mode, type the executable followed by the scene you wish 
to import: "./playlife scene5.txt"

In automatic mode, the user must force-quit the program once it has started 
running.

------------------
Implementation
------------------

This project is implemented in C++, with features included in the 2011 
release (compile using the -std=c++11 flag). To learn more about the 
project's implementation, read the "report.txt" file.


