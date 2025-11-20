#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <memory>
#include <cmath>

// Класс Ромб
template<Scalar T>
class Rhombus : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center_;
    T horizontal_diagonal_, vertical_diagonal_;

public:
    Rhombus(T center_x, T center_y, T horizontal, T vertical)
        : center_(std::make_unique<Point<T>>(center_x, center_y)),
          horizontal_diagonal_(horizontal), vertical_diagonal_(vertical) {}

    Rhombus(const Rhombus& other)
        : center_(std::make_unique<Point<T>>(*other.center_)),
          horizontal_diagonal_(other.horizontal_diagonal_),
          vertical_diagonal_(other.vertical_diagonal_) {}

    Rhombus& operator=(const Rhombus& other) {
        if (this != &other) {
            center_ = std::make_unique<Point<T>>(*other.center_);
            horizontal_diagonal_ = other.horizontal_diagonal_;
            vertical_diagonal_ = other.vertical_diagonal_;
        }
        return *this;
    }

    Point<T> geometric_center() const override {
        return *center_;
    }

    double area() const override {
        return (horizontal_diagonal_ * vertical_diagonal_) / 2.0;
    }

    void print_vertices() const override {
        T half_h = horizontal_diagonal_ / 2;
        T half_v = vertical_diagonal_ / 2;
        
        Point<T> p1(center_->x() - half_h, center_->y());
        Point<T> p2(center_->x(), center_->y() + half_v);
        Point<T> p3(center_->x() + half_h, center_->y());
        Point<T> p4(center_->x(), center_->y() - half_v);
        
        std::cout << "Rhombus vertices: " 
                  << p1 << ", " << p2 << ", " << p3 << ", " << p4 << std::endl;
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Rhombus<T>>(*this);
    }

    bool operator==(const Figure<T>& other) const override {
        if (const Rhombus<T>* other_rhomb = dynamic_cast<const Rhombus<T>*>(&other)) {
            return *center_ == *other_rhomb->center_ &&
                   horizontal_diagonal_ == other_rhomb->horizontal_diagonal_ &&
                   vertical_diagonal_ == other_rhomb->vertical_diagonal_;
        }
        return false;
    }
};

#endif