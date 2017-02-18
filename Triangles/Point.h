//
// Created by Stephen Clyde on 2/3/17.
//

#ifndef TRIANGLES_POINT_H
#define TRIANGLES_POINT_H

#include <string>

class Point {
private:
    double  m_x = 0;
    double  m_y = 0;
    double  m_z = 0;
    bool  m_valid = false;
    const double  m_minDistance = 0.0001;

public:
    Point(const char *str);
    Point(const std::string& pointStr);
    Point(char x, char y, char z, char a);
    Point(double x, double y, double z);

    bool isValid() const { return m_valid; }
    bool isEquivalentTo(const Point &otherPoint) const;
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

private:
    void initialize(const std::string &pointStr);
    void checkForInfinity();
};

#endif //TRIANGLES_POINT_H
