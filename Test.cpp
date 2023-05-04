#pragma

#include "doctest.h"
#include <stdexcept>
using namespace std;
#include "sources/Team.hpp"
using namespace ariel;

TEST_CASE("Point TEST:")
{
    CHECK_NOTHROW(Point(0,0));
    // ILLEGAL POINTS???
    Point a(0,0), b(1,0);
    CHECK_EQ(a.distance(b), 1);
    // more dists
    CHECK_EQ(a.moveTowards(b, 0.5), Point(0.5, 0.5));
    CHECK_EQ(a.moveTowards(b, 0), a);
    CHECK_THROWS(a.moveTowards(b, -1));
    CHECK_NOTHROW(b.print());
}