#pragma once

#include"figure.h"
#include"point.h"

class Romb final: public Figure {

  public:
    Romb() = default;
    Romb(const Point& _upper, const Point& _lower, const Point& _left, const Point& _right, const std::string& _figure_name);
    Romb(const Romb& other) noexcept;

    virtual ~Romb() noexcept = default;

    explicit virtual operator double() const noexcept override;
    Romb& operator=(const Romb&) noexcept;
    Romb& operator=(Romb&&) noexcept; 
    bool operator==(const Romb&) const noexcept;
    bool operator!=(const Romb&) const noexcept;


    virtual double area() const noexcept override;
    virtual double perimetr() const noexcept override;
    virtual Point center() const noexcept override;


    friend std::ostream& operator<<(std::ostream&, const Romb&);
    friend std::istream& operator>>(std::istream&, Romb&);
  private:
    Point upper_point;
    Point lower_point;
    Point left_point;
    Point right_point;
};