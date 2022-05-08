For one of my school reports I decided to estimate pi with Monte Carlo method.
Based on https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/ I prepared a simple program that does x tests with y sample size (which can both be specified inside the code) and writes results inside pidata.txt file.

TODO:
- learn how to write data into a spreadsheet ✓(C++)
- make 100 estimations for sample size in range 10'000 - 10'000'000 with jump of 10'000 and organize them inside a spreadsheet(prepare graph demonstrating results) ✓(C++)
- clean up the program and prepare it to interact with user ✓(python)
- learn how to execute operations on GPU ✓(python)
- implement this algorithm on GPU (if possible) ✓(python)

I encountered problems trying to find proper tutorials for implementing C++ programs on graphics card, so I requested help from one of my teachers.
As I waited to get some C++ related resources(tutorials, documentations, list of technologies available, etc.) I implemented the program(without spreadsheet option) in Python, using CuPy to execute operations on graphics card
