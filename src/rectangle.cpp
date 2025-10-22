#include "rectangle.h"

Rectangle::Rectangle() : x(0), y(0), w(2), h(1) {}

Rectangle::Rectangle(double x, double y, double w, double h)
    : x(x), y(y), w(w), h(h) {}

double Rectangle::center_x() const{
    return x + w / 2.0;
}

double Rectangle::center_y() const{
    return y + h / 2.0;
}

Rectangle::operator double() const {
    return w * h;
}

void Rectangle::print(std::ostream& os) const {
    os << "Координаты вершин прямоугольника (начиная с нижней " 
          "левой точки и по часовой стрелке)\n" 
       << "(" << x << "," << y << ") "
       << "(" << x << "," << y + h << ") "
       << "(" << x + w << "," << y + h << ") "
       << "(" << x + w << "," << y << ")\n";
}

void Rectangle::input(std::istream& is) {
    is >> x >> y >> w >> h;
}

bool Rectangle::operator==(const Figure& right_operand) const {
    const Rectangle* rect = dynamic_cast<const Rectangle*>(&right_operand);
    if (!rect) return false;
    return std::abs(x - rect->x) < 1e-12 && std::abs(y - rect->y) < 1e-12 &&
           std::abs(w - rect->w) < 1e-12 && std::abs(h - rect->h) < 1e-12;
}


Figure& Rectangle::operator=(const Figure& right_operand) {
    if (this != &right_operand) {
        const Rectangle* rect = dynamic_cast<const Rectangle*>(&right_operand);
        if (!rect) {
            throw std::invalid_argument("Нельзя присвоить прямоугольнику не прямоугольник");
        }

        x = rect->x;
        y = rect->y;
        w = rect->w;
        h = rect->h;
    }
    return *this;
}

Figure& Rectangle::operator=(Figure&& right_operand) {
    if (this != &right_operand) {
        const Rectangle* rect = dynamic_cast<const Rectangle*>(&right_operand);
        if (!rect) {
            throw std::invalid_argument("Нельзя присвоить прямоугольнику не прямоугольник");
        }

        x = rect->x;
        y = rect->y;
        w = rect->w;
        h = rect->h;

        const_cast<Rectangle*>(rect)->x = 0;
        const_cast<Rectangle*>(rect)->y = 0;
        const_cast<Rectangle*>(rect)->w = 0;
        const_cast<Rectangle*>(rect)->h = 0;
    }
    return *this;
}

// Rectangle& Rectangle::operator=(const Rectangle& right_operand) {
//     if (this != &right_operand) {
//         const Rectangle* rect = &right_operand;
//         x = rect->x;
//         y = rect->y;
//         w = rect->w;
//         h = rect->h;
//     }
//     return *this;
// }

// Rectangle& Rectangle::operator=(Rectangle&& right_operand) noexcept{
//     if (this != &right_operand) {
//         const Rectangle* rect = &right_operand;

//         x = rect->x;
//         y = rect->y;
//         w = rect->w;
//         h = rect->h;

//         const_cast<Rectangle*>(rect)->x = 0;
//         const_cast<Rectangle*>(rect)->y = 0;
//         const_cast<Rectangle*>(rect)->w = 0;
//         const_cast<Rectangle*>(rect)->h = 0;
//     }
//     return *this;
// }