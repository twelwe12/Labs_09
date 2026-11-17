//////////////////////////////////////////////////////////////////////////////
// macros_9_2.h
// Макроси для завдання 9.2, частина 1.
#pragma once

#include <cmath>
#include <iostream>

#define MAXIMUM(a, b) (((a) > (b)) ? (a) : (b))
#define MINIMUM(a, b) (((a) < (b)) ? (a) : (b))
#define ABSOLUTE(a) (((a) < 0.0) ? -(a) : (a))
#define SQUARE(a) ((a) * (a))
#define CUBE(a) ((a) * (a) * (a))
#define ROOT(a) (std::sqrt(a))
#define LOGICAL_AND(a, b) ((a) && (b))
#define LOGICAL_OR(a, b) ((a) || (b))
#define PRINT_RESULT(name, value) (std::cout << #name " = " << (value) << '\n')
