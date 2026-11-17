//////////////////////////////////////////////////////////////////////////////
// dod.cpp
// Обчислення наступного доданка ряду для ln(x).
// Для a_n = (-1)^(n-1) * (x-1)^n / n:
// a_(n+1) = -a_n * (x-1) * n / (n+1).
#include "dod.h"
#include "var.h"

using namespace nsVar;

void nsDod::dod() {
    a *= -(x - 1.0) * static_cast<double>(n - 1) / static_cast<double>(n);
}
