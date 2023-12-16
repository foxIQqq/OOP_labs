#pragma once

#include"figure.h"
#include"point.h"

class Pentagon final: public Figure {

  public:
    Pentagon() = default;

    Pentagon(const Point& _left_lower, const Point& _right_lower, const Point&  _left_middle, const Point& _right_middle, const Point& _upper, const std::string& _figure_name);

    Pentagon(const Pentagon& other) noexcept;

    virtual ~Pentagon() noexcept = default;

    virtual double area() const noexcept override;
    virtual double perimetr() const noexcept override;
    virtual Point center() const noexcept override;

    explicit virtual operator double() const noexcept override;
    Pentagon& operator=(const Pentagon&) noexcept;
    Pentagon& operator=(Pentagon&&) noexcept;
    bool operator==(const Pentagon&) const noexcept;
    bool operator!=(const Pentagon&) const noexcept;

    friend std::ostream& operator<<(std::ostream&, const Pentagon&);
    friend std::istream& operator>>(std::istream&, Pentagon&);

  private:
    Point left_lower;
    Point right_lower;
    Point left_middle;
    Point right_middle;
    Point upper;

};