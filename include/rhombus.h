#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"


class Rhombus: public Figure
{
public:
    Rhombus();

    // центр + вертикальная диагональ + горизонтальная диагональ
    Rhombus(double cx, double cy, double d1, double d2);

    virtual double center_x() const override;
    virtual double center_y() const override;

    virtual operator double() const override;

    virtual void print(std::ostream& os) const override;
    virtual void input(std::istream& is) override;

    // Rhombus& operator=(const Rhombus& right_operand);
    // Rhombus& operator=(Rhombus&& right_operand) noexcept;
    virtual Figure& operator=(const Figure& right_operand) override;
    virtual Figure& operator=(Figure&& right_operand) override;
    virtual bool operator==(const Figure& right_operand) const override;

private:
    double cx, cy, d1, d2;
};



#endif