# Sokoban Solver using PSVN

This Sokoban solver contains both a problem domain generator using Python to encode a Sokoban level to a PSVN file (problem description formalism) and its respective solver, written in C++.

To use this solver, first you have to encode your Sokoban level in the "sokobanLevel" text file using the following characters:

\@ - Player

\$ - Box

\. - Goal Square

\+ - Player on Goal Square

\* - Box on Goal Square

\# - Wall

Then, you have to execute the "SokobanDomainGenerator.py" file. Both files are in the "src" folder.

After that, open your terminal on the "src" folder and execute the following command: `make outputDomain.SokobanSolver`.

Finally, to utilize the solver itself, you can type the following command line: `./outputDomain.sokobanSolver`.

The solver uses the A* algorithm to find the goal and, by default, blind search. To utilize the Goal Count heuristic you have to type in `goalCount` as an argument when executing the last command line. Also, you can choose to display the steps of the solution by adding the `showSteps` argument as well. Using both, it would look something like `./outputDomain.sokobanSolver showSteps goalCount`.
