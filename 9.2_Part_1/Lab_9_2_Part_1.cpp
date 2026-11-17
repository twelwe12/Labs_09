//////////////////////////////////////////////////////////////////////////////
// Lab_9_2_Part_1.cpp
// Завдання 9.2, частина 1, варіант 18.
#include <cmath>
#include <iostream>
#include "macros_9_2.h"

// Значення вибирає гілку під час компіляції:
// > 10 — max(x^3, (x+y)^2); <= 10 — min(|x-z|, |x+z|).
// Для іншої гілки змініть значення та перекомпілюйте програму.
#ifndef Z_BRANCH_TEST
#define Z_BRANCH_TEST 11
#endif

int main() {
    double x, y, z, w;

    std::cout << "Завдання 9.2, частина 1, варіант 18\n";
    std::cout << "Введіть x, y, z: ";
    if (!(std::cin >> x >> y >> z)) {
        std::cerr << "Помилка: потрібно ввести три числа.\n";
        return 1;
    }

    if (!LOGICAL_AND(std::isfinite(x),
                     LOGICAL_AND(std::isfinite(y), std::isfinite(z)))) {
        std::cerr << "Помилка: значення мають бути скінченними числами.\n";
        return 1;
    }

#if Z_BRANCH_TEST > 10
    if (z <= 10.0) {
        std::cerr << "Ця збірка містить гілку z > 10. Введіть z > 10 або "
                     "змініть Z_BRANCH_TEST на 10 чи менше та перекомпілюйте.\n";
        return 1;
    }

    w = MAXIMUM(CUBE(x), SQUARE(x + y));
    std::cout << "Обрана під час компіляції гілка: z > 10\n";
#else
    if (z > 10.0) {
        std::cerr << "Ця збірка містить гілку z <= 10. Введіть z <= 10 або "
                     "змініть Z_BRANCH_TEST на значення більше 10 та перекомпілюйте.\n";
        return 1;
    }

    w = MINIMUM(ABSOLUTE(x - z), ABSOLUTE(x + z));
    std::cout << "Обрана під час компіляції гілка: z <= 10\n";
#endif

    PRINT_RESULT(w, w);
    return 0;
}
