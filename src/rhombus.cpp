#include "rhombus.h"

Rhombus::Rhombus() : cx(0), cy(0), d1(1), d2(1) {}

Rhombus::Rhombus(double cx, double cy, double d1, double d2)
    : cx(cx), cy(cy), d1(d1), d2(d2) {}

double Rhombus::center_x() const{
    return cx;
}

double Rhombus::center_y() const{
    return cy;
}

Rhombus::operator double() const {
    return 0.5 * d1 * d2;
}

void Rhombus::print(std::ostream& os) const {
    os << "Координаты вершин ромба (начиная с верхней" 
          "точки и по часовой стрелке)\n" 
       << "(" << cx << "," << cy + d1 / 2.0 << ") "
       << "(" << cx + d2 / 2.0 << "," << cy << ") "
       << "(" << cx << "," << cy - d1 / 2.0 << ") "
       << "(" << cx - d2 / 2.0 << "," << cy << ")\n";
}

void Rhombus::input(std::istream& is) {
    is >> cx >> cy >> d1 >> d2;
}

bool Rhombus::operator==(const Figure& right_operand) const {
    const Rhombus* rh = dynamic_cast<const Rhombus*>(&right_operand);
    if (!rh) return false;
    return std::abs(cx - rh->cx) < 1e-12 && std::abs(cy - rh->cy) < 1e-12 &&
           std::abs(d1 - rh->d1) < 1e-12 && std::abs(d2 - rh->d2) < 1e-12;
}



Figure& Rhombus::operator=(const Figure& right_operand) {
    if (this != &right_operand) {
        const Rhombus* rh = dynamic_cast<const Rhombus*>(&right_operand);
        if (!rh) {
            throw std::invalid_argument("Нельзя присвоить ромбу не ромб");
        }

        cx = rh->cx;
        cy = rh->cy;
        d1 = rh->d1;
        d2 = rh->d2;
    }
    return *this;
}

Figure& Rhombus::operator=(Figure&& right_operand) {
    if (this != &right_operand) {
        const Rhombus* rh = dynamic_cast<const Rhombus*>(&right_operand);
        if (!rh) {
            throw std::invalid_argument("Нельзя присвоить ромбу не ромб");
        }

        cx = rh->cx;
        cy = rh->cy;
        d1 = rh->d1;
        d2 = rh->d2;

        const_cast<Rhombus*>(rh)->cx = 0;
        const_cast<Rhombus*>(rh)->cy = 0;
        const_cast<Rhombus*>(rh)->d1 = 0;
        const_cast<Rhombus*>(rh)->d2 = 0;
    }
    return *this;
}


// Rhombus& Rhombus::operator=(const Rhombus& right_operand) {
//     if (this != &right_operand) {
//         const Rhombus* rh = &right_operand;
//         cx = rh->cx;
//         cy = rh->cy;
//         d1 = rh->d1;
//         d2 = rh->d2;
//     }
//     return *this;
// }

// Rhombus& Rhombus::operator=(Rhombus&& right_operand) noexcept{
//     if (this != &right_operand) {
//         const Rhombus* rh = &right_operand;

//         cx = rh->cx;
//         cy = rh->cy;
//         d1 = rh->d1;
//         d2 = rh->d2;

//         const_cast<Rhombus*>(rh)->cx = 0;
//         const_cast<Rhombus*>(rh)->cy = 0;
//         const_cast<Rhombus*>(rh)->d1 = 0;
//         const_cast<Rhombus*>(rh)->d2 = 0;
//     }
//     return *this;
// }