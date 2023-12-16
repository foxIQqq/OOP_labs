#include"pentagon.h"
#include<iostream>
#include<cmath>

Pentagon::Pentagon(const Point& _left_lower, const Point& _right_lower, const Point& _left_middle, const Point& _right_middle, const Point& _upper, const std::string& _figure_name):
    left_lower(_left_lower),left_middle(_left_middle),right_lower(_right_lower),right_middle(_right_middle),upper(_upper),Figure(_figure_name){}

Pentagon::Pentagon(const Pentagon& other) noexcept: left_lower(other.left_lower), right_lower(other.right_lower), left_middle(other.left_middle), right_middle(other.right_middle), upper(other.upper), Figure(other.figure_name) {}


double Pentagon::area() const noexcept {
    double a = Point::line(left_middle, left_lower);
    double b = Point::line(right_middle, right_lower);
    double c = Point::line(right_lower, left_lower);
    double d = Point::line(upper, right_middle);
    double e = Point::line(upper, left_middle);
    double q = Point::line(upper, left_lower);
    double w = Point::line(upper, right_lower);
    double p1 = (a + e + q)*0.5;
    double p2 = (c + q + w)*0.5;
    double p3 = (b + d + w)*0.5;
    double s1 = sqrt(p1*(p1 - a)*(p1 - e)*(p1 - q));
    double s2 = sqrt(p2*(p2 - c)*(p2 - q)*(p2 - w));
    double s3 = sqrt(p3*(p3 - b)*(p3 - d)*(p3 - w)); 
    return s1 + s2 + s3;
}

double Pentagon::perimetr() const noexcept {
    double a = Point::line(left_middle, left_lower);
    double b = Point::line(right_middle, right_lower);
    double c = Point::line(right_lower, left_lower);
    double d = Point::line(upper, right_middle);
    double e = Point::line(upper, left_middle);

    return a + b + c + d + e;
}

Point Pentagon::center() const noexcept {
    double xCenter =  (left_lower.x + left_middle.x + right_lower.x + right_middle.x + upper.x)*0.2;
    double yCenter =  (left_lower.y + left_middle.y + right_lower.y + right_middle.y + upper.y)*0.2;
    return Point{xCenter, yCenter};
}


Pentagon::operator double() const noexcept {
    return this -> area();
}

Pentagon& Pentagon::operator=(const Pentagon& other) noexcept{

    if (this != &other) {
        left_lower = other.left_lower;
        left_middle = other.left_middle;
        right_lower = other.right_lower;
        right_middle = other.right_middle;
        upper = other.upper;
    }

    return *this;
}
Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {

    if (this != &other) {
        left_lower = other.left_lower;
        left_middle = other.left_middle;
        right_lower = other.right_lower;
        right_middle = other.right_middle;
        upper = other.upper;
    }

    return *this;
}
bool Pentagon::operator==(const Pentagon& other) const noexcept {
    return left_lower == other.left_lower && 
    left_middle == other.left_middle && 
    right_lower == other.right_lower && 
    right_middle == other.right_middle && 
    upper == other.upper;
}
bool Pentagon::operator!=(const Pentagon& other) const noexcept {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Pentagon& pent) {
    os << "Left Lower: " << pent.left_lower << std::endl;
    os << "Right Lower: " << pent.right_lower << std::endl;
    os << "Left Middle: " << pent.left_middle << std::endl;
    os << "Right Middle: " << pent.right_middle << std::endl;
    os << "Upper: " << pent.upper << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Pentagon& pent) {
    is >> pent.left_lower;
    is >> pent.right_lower;
    is >> pent.left_middle;
    is >> pent.right_middle;
    is >> pent.upper;

    pent.figure_name = "pentagon";

    return is;
    
}