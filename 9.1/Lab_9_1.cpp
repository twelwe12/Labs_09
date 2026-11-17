//////////////////////////////////////////////////////////////////////////////
// Lab_9_1.cpp
// Головний файл проєкту — введення даних і виведення таблиці.
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsSum;
using namespace nsVar;

int main() {
    cout << "Обчислення ln(x) за рядом Тейлора (варіант 18)\n\n";

    cout << "x_p = ";
    if (!(cin >> x_p)) {
        cerr << "Помилка: введіть числове значення x_p.\n";
        return 1;
    }

    cout << "x_k = ";
    if (!(cin >> x_k)) {
        cerr << "Помилка: введіть числове значення x_k.\n";
        return 1;
    }

    cout << "dx = ";
    if (!(cin >> dx)) {
        cerr << "Помилка: введіть числове значення dx.\n";
        return 1;
    }

    cout << "eps = ";
    if (!(cin >> e)) {
        cerr << "Помилка: введіть числове значення eps.\n";
        return 1;
    }

    if (!std::isfinite(x_p) || !std::isfinite(x_k) || !std::isfinite(dx) ||
        !std::isfinite(e) || x_p > x_k || x_p <= 0.0 || x_k > 2.0 ||
        dx <= 0.0 || e <= 0.0) {
        cerr << "Помилка: потрібно 0 < x_p <= x_k <= 2, dx > 0 та eps > 0.\n";
        return 1;
    }

    cout << "\nТаблиця значень функції ln(x)\n";
    cout << left << setw(14) << "x"
         << setw(20) << "ln(x)"
         << setw(20) << "Сума ряду"
         << "Доданків n\n";
    cout << string(55, '-') << '\n';
    cout << fixed << setprecision(10);

    x = x_p;
    while (x <= x_k) {
        sum();

        cout << left << setw(14) << x
             << setw(20) << std::log(x)
             << setw(20) << s
             << n << '\n';

        const double nextX = x + dx;
        if (nextX <= x) {
            cerr << "Помилка: крок dx надто малий для цього значення x.\n";
            return 1;
        }
        x = nextX;
    }

    return 0;
}
