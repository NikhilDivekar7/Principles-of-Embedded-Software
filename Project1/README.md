# pesproject1_vipraja_nikhil
This is a private repository for Project 1. The contributors of this project are Nikhil Divekar and Vipraja Patil.

This project includes source and header files for memory, conversion, debug, platform, main and project1.

memory.c/memory.h
This implementation file provides the function definitions for copying data using pointers from one memory location to another,setting data, reversing the order of bytesfrom certain memory locations.

conversion.c/conversion.h
This implementation file provides the function definitions for various data manipulation operations.

debug.c/debug.h
The implementation file is to enable/disable debug printing with a compile time switch.

platform.h
This file should help you create an independent layer allowing you to switch between platform specific lower-level functions.

main.c
We just call a function that is defined in the project1.c source file. We must use a compile time switch that wraps this function. This way we can have a simple main() function that can switch to the project deliverable we wish to call by specifying the
-DPROJECT1 compile time switch.

project1.c/project1.h
These files provide some simple testing conditions for the project 1 functions.
