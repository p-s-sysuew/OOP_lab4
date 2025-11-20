#include <iostream>
#include <memory>
#include "./include/figures_utils.h"

int main() {
    // Пример работы с массивом базового типа Figure*
    Array<std::shared_ptr<Figure<int>>> figures;

    // Ввод фигур
    std::cout << "=== Создание фигур ===" << std::endl;
    
    // Трапеция
    auto trap = std::make_shared<Trapezoid<int>>(0, 0, 4, 0, 1, 3, 3, 3);
    figures.push_back(trap);
    
    // Ромб
    auto rhomb = std::make_shared<Rhombus<int>>(0, 0, 6, 4);
    figures.push_back(rhomb);
    
    // Пятиугольник
    auto pent = std::make_shared<Pentagon<int>>(0, 0, 5);
    figures.push_back(pent);

    // Вывод информации о фигурах
    std::cout << "=== Информация о фигурах ===" << std::endl;
    print_figures_info(figures);

    // Вычисление общей площади
    std::cout << "=== Общая площадь ===" << std::endl;
    std::cout << "Общая площадь всех фигур: " << total_area(figures) << std::endl;

    // Проверка оператора приведения к double
    std::cout << "=== Проверка преобразования типов ===" << std::endl;
    double area_as_double = static_cast<double>(*trap);
    std::cout << "Площадь трапеции как double: " << area_as_double << std::endl;

    // Удаление фигуры по индексу
    std::cout << "=== После удаления фигуры с индексом 1 ===" << std::endl;
    figures.remove(1);
    print_figures_info(figures);

    // Проверка работы с конкретными типами фигур
    std::cout << "=== Тест массива конкретных типов ===" << std::endl;
    Array<std::shared_ptr<Rhombus<int>>> rhombus_array;
    rhombus_array.push_back(std::make_shared<Rhombus<int>>(0, 0, 5, 3));
    rhombus_array.push_back(std::make_shared<Rhombus<int>>(2, 2, 4, 6));

    for (size_t i = 0; i < rhombus_array.size(); ++i) {
        std::cout << "Площадь ромба " << i + 1 << ": " << rhombus_array[i]->area() << std::endl;
    }

    return 0;
}