#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include <memory>

// Базовый класс Figure
template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    // Виртуальные методы
    virtual Point<T> geometric_center() const = 0;
    virtual double area() const = 0;
    virtual void print_vertices() const = 0;
    virtual std::unique_ptr<Figure<T>> clone() const = 0;

    // Оператор приведения к double (площадь)
    explicit virtual operator double() const {
        return area();
    }

    // Виртуальные операторы сравнения
    virtual bool operator==(const Figure<T>& other) const = 0;
    virtual bool operator!=(const Figure<T>& other) const {
        return !(*this == other);
    }
};

#endif