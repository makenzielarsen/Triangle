//
// Created by Stephen Clyde on 2/3/17.
//

#include "TriangleTester.h"

#include <iostream>
#include <cmath>

#include "../Triangle.h"
#include "../Utils.h"

void TriangleTester::testFirstConstructor()
{
    std::cout << "Execute TriangleTester::testConstructorWithStrings" << std::endl;

    Point** points = new Point*[3];
    points[0] = new Point(1,2,8);
    points[1] = new Point(3,1,4);
    points[2] = new Point(6,4,3);

    Triangle t(points);
    if (!t.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                 << t.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t.computerArea(), 9.35414, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                 << t.computerArea() << std::endl;
        return;
    }

    const Point* p = t.getPoint(0);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=1 || p->getY()!=2 || p->getZ()!=8)
    {
        std::cout << "Point 0 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }

    p = t.getPoint(1);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=3 || p->getY()!=1 || p->getZ()!=4)
    {
        std::cout << "Point 1 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = t.getPoint(2);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=6 || p->getY()!=4 || p->getZ()!=3)
    {
        std::cout << "Point 2 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }
}

void TriangleTester::testSecondConstructor()
{
    std::cout << "Execute TriangleTester::testSecondConstructor" << std::endl;
    std::string triangleOne = "1,2,8|3,1,4|6,4,3";
    Triangle one(triangleOne);
    if (!one.isValid()) {
        std::cout << "Failure constructing valid triangle." << std::endl;
    }

    if (!one.isTriangle()) {
        std::cout << "Failure constructing triangle." << std::endl;
    }

    if (one.getTriangleType()!='S') {
        std::cout << "Triangle: unexpected type of "
                  << one.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(one.computerArea(), 9.35414, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << one.computerArea() << std::endl;
        return;
    }

    const Point* p = one.getPoint(0);

    if (p== nullptr) {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=1 || p->getY()!=2 || p->getZ()!=8) {
        std::cout << "Point 0 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }

    p = one.getPoint(1);
    if (p== nullptr) {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=3 || p->getY()!=1 || p->getZ()!=4) {
        std::cout << "Point 1 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = one.getPoint(2);
    if (p== nullptr) {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=6 || p->getY()!=4 || p->getZ()!=3) {
        std::cout << "Point 2 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }
}

void TriangleTester::testEquilateralTriangles()
{
    std::cout << "Execute TriangleTester::testEquilateralTriangles" << std::endl;

    std::string triangleStr = "-10,0,0|10,0,0|0,17.32050808,0";
    Triangle t1(triangleStr);
    if (!t1.isValid()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='E') {
        std::cout << "Triangle: unexpected type of "
                 << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computerArea(), 173.205, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                 << t1.computerArea() << std::endl;
        return;
    }
}

void TriangleTester::testIsoscelesTriangles() {
    std::cout << "Execute TriangleTester::testIsoscelesTriangles" << std::endl;

    std::string triangleStr2 = "-25,0,0|25,0,0|0,42.48398223432,0";
    Triangle t2(triangleStr2);
    if (!t2.isValid()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType()!='I') {
        std::cout << "Triangle: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computerArea(), 1062.1, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t2.computerArea() << std::endl;
        return;
    }
}

void TriangleTester::testScaleneTriangles() {
    std::cout << "Execute TriangleTester::testScaleneTriangles" << std::endl;

    std::string triangleStr2 = "-25,2,0|25,0,16|0,42.48398223432,0";
    Triangle t2(triangleStr2);
    if (!t2.isValid()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType()!='S') {
        std::cout << "Triangle: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computerArea(), 1104.748, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t2.computerArea() << std::endl;
        return;
    }
}

void TriangleTester::testInvalid() {
    std::cout << "Execute TriangleTester::testInvalid" << std::endl;

    Triangle one(nullptr);
    if (one.isValid()) {
        std::cout << "Failure to fail the constructor triangle from 3 invalid points" << std::endl;
        return;
    }
}

void TriangleTester::testNonTriangles() {
    std::cout << "Execute TriangleTester::testNonTriangles" << std::endl;

    Point notATriangle = "1,0,0|2,0,0|3,0,0";
    Point* passable = &notATriangle;
    Triangle one(&passable);
    if (one.isValid()) {
        std::cout << "Failure to fail the constructor triangle from 3 invalid points" << std::endl;
        return;
    }
}
