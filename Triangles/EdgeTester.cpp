//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.h"

#include <iostream>
#include <cmath>
#include "../Point.h"
#include "../Edge.h"

void EdgeTester::testEdge01() {
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0,0,0);
    Point p1(1,0,0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength()!=1)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX()!=INFINITY)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY()!=0)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ()!=0)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02() {
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1,0,0);
    Point p1(3,4,5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges()
{
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;

    Point one(1,2,3);
    Point two(2,3,4);
    Edge One(&one, &two);
    Point three(3,4,5);
    Point four(4,5,6);
    Edge Two(&three, &four);
    if (!One.isParallelTo(Two)) {
        std::cout << "Failure in Parallel Edges expecting parallel" << std::endl;
    }
}

void EdgeTester::testNonParallelEdges()
{
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;

    Point one(1,2,3);
    Point two(8,9,10);
    Edge One(&one, &two);
    Point three(4,3,4);
    Point four(1,2,3);
    Edge Two(&three, &four);
    if (One.isParallelTo(Two)) {
        std::cout << "Failure in Parallel Edges expecting non-parallel" << std::endl;
    }
}

void EdgeTester::testNonLengthEdges()
{
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;

    Point one(1,2,3);
    Point two(1,2,3);
    Edge One(&one, &two);

    Point three(1,2,3);
    Point four(1.00000000000000000000001,2.00000000000000000000001,3.00000000000000000000001);
    Edge Two(&three, &four);

    if (One.getLength() != 0) {
        std::cout << "Failure in length computation, expecting 0, got " << One.getLength() << std::endl;
    }
    if (Two.getLength() != 0) {
        std::cout << "Failure in length computation, expecting 0, got " << One.getLength() << std::endl;
    }
}

void EdgeTester::testBadEdges()
{
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;

    Edge One(nullptr, nullptr);

    if (One.isValid()) {
        std::cout << "Failure in edge manufacturing side shouldn't be valid." << std::endl;
    }
}
