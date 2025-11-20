#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <memory>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Класс Пятиугольник
template<Scalar T>
class Pentagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T radius_;

public:
    Pentagon(T center_x, T center_y, T radius)
        : center_(std::make_unique<Point<T>>(center_x, center_y)), radius_(radius) {}

    Pentagon(const Pentagon& other)
        : center_(std::make_unique<Point<T>>(*other.center_)), radius_(other.radius_) {}

    Pentagon& operator=(const Pentagon& other) {
        if (this != &other) {
            center_ = std::make_unique<Point<T>>(*other.center_);
            radius_ = other.radius_;
        }
        return *this;
    }

    Point<T> geometric_center() const override {
        return *center_;
    }

    double area() const override {
        double side = 2 * radius_ * std::sin(M_PI / 5);
        double apothem = radius_ * std::cos(M_PI / 5);
        return (5 * side * apothem) / 2.0;
    }

    void print_vertices() const override {
        std::cout << "Pentagon vertices: ";
        for (int i = 0; i < 5; ++i) {
            double angle = 2 * M_PI * i / 5;
            T x = center_->x() + radius_ * std::cos(angle);
            T y = center_->y() + radius_ * std::sin(angle);
            std::cout << "(" << x << ", " << y << ")";
            if (i < 4) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Pentagon<T>>(*this);
    }

    bool operator==(const Figure<T>& other) const override {
        if (const Pentagon<T>* other_pent = dynamic_cast<const Pentagon<T>*>(&other)) {
            return *center_ == *other_pent->center_ && radius_ == other_pent->radius_;
        }
        return false;
    }
};

#endif