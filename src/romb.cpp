#include"romb.h"
#include<cmath>
#include<iostream>


Romb::Romb(const Point& upper, const Point& lower, const Point& left, const Point& right, const std::string& name): upper_point(upper), lower_point(lower), left_point(left), right_point(right), Figure(name){}

Romb::Romb(const Romb& other) noexcept: upper_point(other.upper_point), lower_point(other.lower_point), left_point(other.left_point), right_point(other.right_point), Figure(other.figure_name){}

double Romb::area() const noexcept {

    double d1 = Point::line(upper_point, lower_point);
    double d2 = Point::line(left_point, right_point);

    return d1*d2*0.5;
}

double Romb::perimetr() const noexcept {
    double a = Point::line(lower_point, left_point);
    std::cout << "   a     :" << a<<"\n";
    return 4.0*a;
}

Point Romb::center() const noexcept {
    double CenterX = (upper_point.x + lower_point.x + right_point.x + left_point.x) * 0.25;
    double CenterY = (upper_point.y + lower_point.y + left_point.y + right_point.y)*0.25;

    return Point{CenterX, CenterY};
}


Romb::operator double () const noexcept {
    return this -> area();
}
Romb& Romb::operator=(const Romb& other) noexcept {
    
    if (this != &other) {
        upper_point = other.upper_point;
        lower_point = other.lower_point;
        left_point = other.left_point;
        right_point = other.right_point;
    }

    return *this;
}
Romb& Romb::operator=(Romb&& other) noexcept {
    
    if (this != &other) {
        upper_point = other.upper_point;
        lower_point = other.lower_point;
        left_point = other.left_point;
        right_point = other.right_point;
    }

    return *this;
}
bool Romb::operator==(const Romb& other) const noexcept {
    return upper_point == other.upper_point && lower_point == other.lower_point && right_point == other.right_point && left_point == other.left_point;
}
bool Romb::operator!=(const Romb& other) const noexcept {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Romb& romb){
    os << "Upper point: " << romb.upper_point << std::endl;
    os << "Left point: " << romb.left_point << std::endl;
    os << "Right point: " << romb.right_point << std::endl;
    os << "Lower point: " << romb.lower_point << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Romb& romb) {
    is >> romb.upper_point;
    is >> romb.left_point;
    is >> romb.right_point;
    is >> romb.lower_point;

    romb.figure_name = "romb";
    
    return is;
}   