#pragma once
#include<iostream>

class Point {
  public:
    double x;
    double y;
  
    Point();
    Point(double, double);
    Point(const Point&);
    ~Point() = default;

    Point& operator=(const Point&);
    Point& operator=(Point&&);
    bool operator==(const Point&) const noexcept;
    bool operator!=(const Point&) const noexcept;

    friend std::ostream& operator<<(std::ostream&, const Point&) noexcept;
    friend std::istream& operator>>(std::istream&, Point&) noexcept;

    static double line(const Point&, const Point&) noexcept;
};