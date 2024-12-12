#include <gtest/gtest.h>
#include "sat.h"  // Import the function to be tested

TEST(HasIntersectionTest, NoIntersection) {
    std::vector<Point2d> polygon1 = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    std::vector<Point2d> polygon2 = {{2, 2}, {3, 2}, {3, 3}, {2, 3}};

    bool result = HasIntersection(polygon1, polygon2);

    EXPECT_FALSE(result);
}

TEST(HasIntersectionTest, Intersection) {
    std::vector<Point2d> polygon1 = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    std::vector<Point2d> polygon2 = {{0.5, 0.5}, {1.5, 0.5}, {1.5, 1.5}, {0.5, 1.5}};

    bool result = HasIntersection(polygon1, polygon2);

    EXPECT_TRUE(result);
}

TEST(HasIntersectionTest, SamePolygon) {
    std::vector<Point2d> polygon1 = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

    bool result = HasIntersection(polygon1, polygon1);

    EXPECT_TRUE(result);
}

TEST(HasIntersectionTest, EmptyPolygon1) {
    std::vector<Point2d> polygon1;
    std::vector<Point2d> polygon2 = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};

    bool result = HasIntersection(polygon1, polygon2);

    EXPECT_FALSE(result);
}

TEST(HasIntersectionTest, EmptyPolygon2) {
    std::vector<Point2d> polygon1 = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    std::vector<Point2d> polygon2;

    bool result = HasIntersection(polygon1, polygon2);

    EXPECT_FALSE(result);
}