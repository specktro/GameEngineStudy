//
// Created by specktro on 17/09/25.
//
#include <iostream>
#include "vector2d.h"

int main() {
    Vector2D v1(3.0f, 4.0f);
    Vector2D v2(1.0f, 2.0f);

    Vector2D sum = v1 + v2;      // Should be (4, 6)
    Vector2D diff = v1 - v2;     // Should be (2, 2)
    float len = v1.length();     // Should be 5.0
    float dot = v1.dot(v2);      // Should be 11.0

    std::cout << "Sum: (" << sum.getX() << ", " << sum.getY() << ")" << std::endl;
    std::cout << "Diff: (" << diff.getX() << ", " << diff.getY() << ")" << std::endl;
    std::cout << "Length of v1: " << len << std::endl;
    std::cout << "Dot product: " << dot << std::endl;

    return 0;
}