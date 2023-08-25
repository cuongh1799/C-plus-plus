/*
In every .h file, include the header guards with the following format:
#ifndef HEADERFILE_H
#define HEADERFILE_H
and end the file with #endif
The purpose is to prevent multiple inclusion of the same header file in the
program. In other words, the first time HEADERFILE_H is not defined, it will
get defined and header file is included. The next time when compiler checks the
HEADERFILE_H, if it has been defined, it will not be included again.
For further information, you may refer to:
https://www.learncpp.com/cpp-tutorial/header-guards/ */
