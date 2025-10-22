#include "figure.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"
#include <iostream>
#include <string>

const int MAX_FIGURES = 100;

double total_area(Figure* figures[], int count) {
    double sum = 0.0;
    for (int i = 0; i < count; ++i) {
        if (figures[i] != nullptr) {
            sum += static_cast<double>(*figures[i]);
        }
    }
    return sum;

}


int main() {
    Figure* figures[MAX_FIGURES];
    int count = 0;

    std::cout << "Вводите номер для задания фигуры" << std::endl;
    std::cout << "0.Закончить ввод; 1.Прямоугольник; 2.Трапеция; 3.Ромб" << std::endl;
    int choice;
    std::cin >> choice;

    // === ВВОД ФИГУР ===
    while (choice && count < MAX_FIGURES) {
        Figure* f = nullptr;
        if (choice == 1) {
            std::cout << "Введите координаты левой нижней точки, длину и ширину прямоугольника" << std::endl;
            f = new Rectangle();
        } else if (choice == 2) {
            std::cout << "Введите координаты центра основания, длину нижнего и верхнего основания, высоту трапеции" << std::endl;
            f = new Trapezoid();
        } else if (choice == 3) {
            std::cout << "Введите координаты пересечения диагоналей, длину вертикальной и горизонтальной диагонали" << std::endl;
            f = new Rhombus();
        } else {
            std::cout << "Неверный номер" << std::endl;
            continue;
        }

        std::cin >> *f;
        figures[count++] = f;
        std::cout << "0.Закончить ввод; 1.Прямоугольник; 2.Трапеция; 3.Ромб" << std::endl;
        std::cin >> choice;
    }
    std::cout << std::endl;
    // === ВЫВОД ЦЕНТРА, ПЛОЩАДИ, КООРДИНАТ ФИГУР ===
    std::cout << "=== Вывод информации о фигурах ===" << std::endl;
    for (int i = 0; i < count; ++i) {
        double cx = figures[i]->center_x();
        double cy = figures[i]->center_y();
        double area = static_cast<double>(*figures[i]);
        std::cout << "Фигура " << i << ": центр=(" << cx << ", " << cy << "), площадь=" << area << std::endl;
        std::cout << *figures[i] << std::endl;
    }
    std::cout << "Общая площадь=" << total_area(figures, count) << std::endl;

    // === УДАЛЕНИЕ ПО ИНДЕКСУ ===

    if (count > 0) {
        std::cout << "Введите индекс фигуры для удаления (0-" << count - 1 << ")" << std::endl;
        int index;
        std::cin >> index;
        if (index >= 0 && index < count) {
            delete figures[index];
            for (int i = index; i < count - 1; ++i) {
                figures[i] = figures[i + 1];
            }
            --count;
            std::cout << "Фигура " << index << " удалена." << std::endl;
            std::cout << "Общая площадь=" << total_area(figures, count) << std::endl;
        } else { 
            std::cout << "Неверный индекс." << std::endl;
        }
    }
    std::cout << std::endl;
    // === ПЕРЕГРУЗКА ОПЕРАТОРОВ ===
    std::cout << "=== ПЕРЕГРУЗКА ОПЕРАТОРОВ ===" << std::endl;

    Rectangle r1(1, 1, 4, 3);
    Rectangle r2(0, 0, 2, 5);
    Rectangle r3;
    Rectangle r4;
    Figure* figures2[]{&r1, &r2, &r3, &r4};

    bool z = (*figures2[1] == *figures2[2]);
    std::cout << "r2 == r3? " << (z ? "True" : "False") << std::endl;
    *figures2[2] = *figures2[1];
    z = (*figures2[1] == *figures2[2]);
    std::cout << "r3 = r2" << std::endl;
    std::cout << "r2 == r3? " << (z ? "True" : "False") << std::endl;

    *figures2[3] = std::move(*figures2[0]);
    std::cout << "Перемещающее присваивание r1 в r4" << std::endl;
    std::cout << "r4: " << *figures2[3] << std::endl; 
    std::cout << "r1: " << *figures2[0] << std::endl; 

    for (int i = 0; i < count; ++i) {
        delete figures[i];
    }
    std::cout << "=== ПРОГРАММА ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}