# Base-Converter

Project for CS281

This is a C++ program that does base number conversion. This program operates from the command line like the following:
``` sh
./convert 2025 10 6
2025_10 = 13213_6
```

This program takes three command-line parameters: `x` `b1` and `b2` where:\
- `x` is the current value that you want to convert
- `b1` is the base x is currently expressed in
- `b2` is the base you want to convert x to

## How to Run
First create an executable named convert using the -o compilation flag.
``` sh
g++ -o convert convert.cpp
```

## Valid Bases
Arguments `b1` and `b2` are bases (base of the expressed value x and the base you want to convert to). Valid values for bases are betweeb 2 and 16 inclusive. For bases above base 10, we use A, B, C, D, E, F as "digits" necessary for the base.

For this project, assume that x will always be a positive integer between 0 and 1 million (as a base 10 value).

## Checking
This program contains basic checking:
- if `b1` or `b2` is not a valid base, we indicate so and end the program
- if `x` is not expressed using valid digits for the base, we indicate so and end the program
