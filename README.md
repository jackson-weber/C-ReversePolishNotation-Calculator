# C-ReversePolishNotation-Calculator

From [Wikipedia](https://en.wikipedia.org/wiki/Reverse_Polish_notation "Wikipedia article"), "Reverse Polish Notation (RPN) is a mathematical notation in which operators *precede* their operands". 

This calculator takes inputs in RPN and outputs the answer. It handles the inputs and outputs in floats and uses stacks to perform the arithmatic operations. It has a complete stack integration with push, pop, peek, check if empty, and delete. 

The main code is in `calc.c`, the structure and function definitions are contained in the `calc.h` header file, and the Makefule contains the target `all` to compile the executable file `calc`.
