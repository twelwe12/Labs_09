//////////////////////////////////////////////////////////////////////////////
// sum.cpp
// Обчислення суми ряду Тейлора для ln(x).
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 1;
    a = x - 1.0;  // перший доданок a_1
    s = a;

    while (std::fabs(a) > e) {
        ++n;
        dod();
        s += a;
    }
}
