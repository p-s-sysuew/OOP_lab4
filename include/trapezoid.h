#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <cmath>
#include <memory>

// Класс Трапеция
template<Scalar T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p1_, p2_, p3_, p4_;

public:
    Trapezoid(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4)
        : p1_(std::make_unique<Point<T>>(x1, y1)),
          p2_(std::make_unique<Point<T>>(x2, y2)),
          p3_(std::make_unique<Point<T>>(x3, y3)),
          p4_(std::make_unique<Point<T>>(x4, y4)) {}

    Trapezoid(const Trapezoid& other)
        : p1_(std::make_unique<Point<T>>(*other.p1_)),
          p2_(std::make_unique<Point<T>>(*other.p2_)),
          p3_(std::make_unique<Point<T>>(*other.p3_)),
          p4_(std::make_unique<Point<T>>(*other.p4_)) {}

    Trapezoid& operator=(const Trapezoid& other) {
        if (this != &other) {
            p1_ = std::make_unique<Point<T>>(*other.p1_);
            p2_ = std::make_unique<Point<T>>(*other.p2_);
            p3_ = std::make_unique<Point<T>>(*other.p3_);
            p4_ = std::make_unique<Point<T>>(*other.p4_);
        }
        return *this;
    }

    Point<T> geometric_center() const override {
        T center_x = (p1_->x() + p2_->x() + p3_->x() + p4_->x()) / 4;
        T center_y = (p1_->y() + p2_->y() + p3_->y() + p4_->y()) / 4;
        return Point<T>(center_x, center_y);
    }

    double area() const override {
        // Вычисление площади трапеции
        double base1 = std::sqrt(std::pow(p2_->x() - p1_->x(), 2) + std::pow(p2_->y() - p1_->y(), 2));
        double base2 = std::sqrt(std::pow(p4_->x() - p3_->x(), 2) + std::pow(p4_->y() - p3_->y(), 2));
        double height = std::abs(p1_->y() - p3_->y()); // Упрощенное вычисление высоты
        return (base1 + base2) * height / 2.0;
    }

    void print_vertices() const override {
        std::cout << "Trapezoid vertices: " 
                  << *p1_ << ", " << *p2_ << ", " << *p3_ << ", " << *p4_ << std::endl;
    }

    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Trapezoid<T>>(*this);
    }

    bool operator==(const Figure<T>& other) const override {
        if (const Trapezoid<T>* other_trap = dynamic_cast<const Trapezoid<T>*>(&other)) {
            return *p1_ == *other_trap->p1_ && *p2_ == *other_trap->p2_ &&
                   *p3_ == *other_trap->p3_ && *p4_ == *other_trap->p4_;
        }
        return false;
    }
};

#endif