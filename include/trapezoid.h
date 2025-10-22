#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "figure.h"


class Trapezoid: public Figure
{
public:
    Trapezoid();

    // центр нижнего основания + длина нижнего и верхнего основания + высота
    Trapezoid(double cx_bottom, double cy_bottom, double bottom, double top, double h);

    virtual double center_x() const override;
    virtual double center_y() const override;

    virtual operator double() const override;

    virtual void print(std::ostream& os) const override;
    virtual void input(std::istream& is) override;

    // Trapezoid& operator=(const Trapezoid& right_operand);
    // Trapezoid& operator=(Trapezoid&& right_operand) noexcept;

    virtual Figure& operator=(const Figure& right_operand) override;
    virtual Figure& operator=(Figure&& right_operand) override;
    virtual bool operator==(const Figure& right_operand) const override;

private:
    double cx_bottom, cy_bottom, bottom, top, h;
};



#endif