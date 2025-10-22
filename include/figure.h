#ifndef FIGURE_H
#define FIGURE_H


#include <iostream>


class Figure {
    friend std::ostream& operator<<(std::ostream& os, const Figure& f);
    friend std::istream& operator>>(std::istream& is, Figure& f);
public: 
    virtual ~Figure() = default;
    
    virtual double center_x() const = 0;
    virtual double center_y() const = 0;

    virtual operator double() const = 0;

    virtual Figure& operator=(const Figure& right_operand) { return *this; };
    virtual Figure& operator=(Figure&& right_operand) {return *this; };
    virtual bool operator==(const Figure& right_operand) const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void input(std::istream& is) = 0;
};


#endif