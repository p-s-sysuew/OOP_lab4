#ifndef FIGURES_UTILS_H
#define FIGURES_UTILS_H

#include "array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "./ pentagon.h"
#include <memory>
#include <iostream>

// Функции для работы с массивом фигур
template<Scalar T>
void print_figures_info(const Array<std::shared_ptr<Figure<T>>>& figures) {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":" << std::endl;
        std::cout << "Geometric center: " << figures[i]->geometric_center() << std::endl;
        figures[i]->print_vertices();
        std::cout << "Area: " << figures[i]->area() << std::endl;
        std::cout << std::endl;
    }
}

template<Scalar T>
double total_area(const Array<std::shared_ptr<Figure<T>>>& figures) {
    double total = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total += figures[i]->area();
    }
    return total;
}

#endif