#include "trapezoid.h"

Trapezoid::Trapezoid() : cx_bottom(0), cy_bottom(0), bottom(2), top(1), h(1) {}

Trapezoid::Trapezoid(double cx_bottom, double cy_bottom, double bottom, double top, double h)
    : cx_bottom(cx_bottom), cy_bottom(cy_bottom), bottom(bottom), top(top), h(h) {}

double Trapezoid::center_x() const{
    return cx_bottom;
}

double Trapezoid::center_y() const{
    return cy_bottom + h / 3.0 * (bottom + top * 2.0) / (bottom + top);
}

Trapezoid::operator double() const {
    return (bottom + top) * 0.5 * h;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Координаты вершин трапеции (начиная с верхней " 
          "левой точки и по часовой стрелке)\n" 
       << "(" << cx_bottom - top / 2.0 << "," << cy_bottom + h << ") "
       << "(" << cx_bottom + top / 2.0 << "," << cy_bottom + h << ") "
       << "(" << cx_bottom + bottom / 2.0 << "," << cy_bottom << ") "
       << "(" << cx_bottom - bottom / 2.0 << "," << cy_bottom << ")\n";
}

void Trapezoid::input(std::istream& is) {
    is >> cx_bottom >> cy_bottom >> bottom >> top >> h;
}

bool Trapezoid::operator==(const Figure& right_operand) const {
    const Trapezoid* tr = dynamic_cast<const Trapezoid*>(&right_operand);
    if (!tr) return false;
    return std::abs(cx_bottom - tr->cx_bottom) < 1e-12 && std::abs(cy_bottom - tr->cy_bottom) < 1e-12 &&
           std::abs(bottom - tr->bottom) < 1e-12 && std::abs(top - tr->top) < 1e-12 && 
           std::abs(h - tr->h) < 1e-12;
}

Figure& Trapezoid::operator=(const Figure& right_operand) {
    if (this != &right_operand) {
        const Trapezoid* tr = dynamic_cast<const Trapezoid*>(&right_operand);
        if (!tr) {
            throw std::invalid_argument("Нельзя присвоить трапеции не трапецию");
        }

        cx_bottom = tr->cx_bottom;
        cy_bottom = tr->cy_bottom;
        bottom = tr->bottom;
        top = tr->top;
        h = tr->h;
    }
    return *this;
}

Figure& Trapezoid::operator=(Figure&& right_operand) {
    if (this != &right_operand) {
        const Trapezoid* tr = dynamic_cast<const Trapezoid*>(&right_operand);
        if (!tr) {
            throw std::invalid_argument("Нельзя присвоить трапеции не трапецию");
        }

        cx_bottom = tr->cx_bottom;
        cy_bottom = tr->cy_bottom;
        bottom = tr->bottom;
        top = tr->top;
        h = tr->h;

        const_cast<Trapezoid*>(tr)->cx_bottom = 0;
        const_cast<Trapezoid*>(tr)->cy_bottom = 0;
        const_cast<Trapezoid*>(tr)->bottom = 0;
        const_cast<Trapezoid*>(tr)->top = 0;
        const_cast<Trapezoid*>(tr)->h = 0;
    }
    return *this;
}

// Trapezoid& Trapezoid::operator=(const Trapezoid& right_operand) {
//     if (this != &right_operand) {
//         const Trapezoid* tr = &right_operand;
//         cx_bottom = tr->cx_bottom;
//         cy_bottom = tr->cy_bottom;
//         bottom = tr->bottom;
//         top = tr->top;
//         h = tr->h;
//     }
//     return *this;
// }

// Trapezoid& Trapezoid::operator=(Trapezoid&& right_operand) noexcept {
//     if (this != &right_operand) {
//         const Trapezoid* tr = &right_operand;

//         cx_bottom = tr->cx_bottom;
//         cy_bottom = tr->cy_bottom;
//         bottom = tr->bottom;
//         top = tr->top;
//         h = tr->h;

//         const_cast<Trapezoid*>(tr)->cx_bottom = 0;
//         const_cast<Trapezoid*>(tr)->cy_bottom = 0;
//         const_cast<Trapezoid*>(tr)->bottom = 0;
//         const_cast<Trapezoid*>(tr)->top = 0;
//         const_cast<Trapezoid*>(tr)->h = 0;
//     }
//     return *this;
// }