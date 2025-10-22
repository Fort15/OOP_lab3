#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"


class Rectangle: public Figure
{
public:
    Rectangle();

    // левый нижний угол + ширина + высота
    Rectangle(double x, double y, double w, double h);

    virtual double center_x() const override;
    virtual double center_y() const override;

    virtual operator double() const override;

    virtual void print(std::ostream& os) const override;
    virtual void input(std::istream& is) override;

    // Rectangle& operator=(const Rectangle& right_operand);
    // Rectangle& operator=(Rectangle&& right_operand) noexcept;
    virtual Figure& operator=(const Figure& right_operand) override;
    virtual Figure& operator=(Figure&& right_operand) override;
    virtual bool operator==(const Figure& right_operand) const override;

private:
    double x, y, w, h;
};



#endif