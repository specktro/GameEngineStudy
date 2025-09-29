//
// Created by specktro on 17/09/25.
//
#include <iostream>
#include "vector2d.h"

// Add to your main.cpp or create a separate test file
void testAdvancedVectorOperations() {
    std::cout << "=== Testing Advanced Vector Operations ===" << std::endl;

    // Test angleBetween
    Vector2D right(1, 0);
    Vector2D up(0, 1);
    Vector2D diagonal(1, 1);

    std::cout << "Angle between right and up: "
              << right.angleBetween(up) << " radians" << std::endl;  // Should be ~1.57 (π/2)
    std::cout << "Angle between right and diagonal: "
              << right.angleBetween(diagonal) << " radians" << std::endl;  // Should be ~0.785 (π/4)

    // Test lerp
    Vector2D start(0, 0);
    Vector2D end(100, 100);

    Vector2D quarter = Vector2D::lerp(start, end, 0.25f);
    Vector2D half = Vector2D::lerp(start, end, 0.5f);
    Vector2D threeQuarter = Vector2D::lerp(start, end, 0.75f);

    std::cout << "Lerp 25%: (" << quarter.getX() << ", " << quarter.getY() << ")" << std::endl;
    std::cout << "Lerp 50%: (" << half.getX() << ", " << half.getY() << ")" << std::endl;
    std::cout << "Lerp 75%: (" << threeQuarter.getX() << ", " << threeQuarter.getY() << ")" << std::endl;

    // Test fromAngle
    Vector2D east = Vector2D::fromAngle(0);           // Should be (1, 0)
    Vector2D north = Vector2D::fromAngle(1.5708f);    // π/2, should be (0, 1)
    Vector2D west = Vector2D::fromAngle(3.14159f);    // π, should be (-1, 0)

    std::cout << "East: (" << east.getX() << ", " << east.getY() << ")" << std::endl;
    std::cout << "North: (" << north.getX() << ", " << north.getY() << ")" << std::endl;
    std::cout << "West: (" << west.getX() << ", " << west.getY() << ")" << std::endl;
}

int main() {
    testAdvancedVectorOperations();

    return 0;
}