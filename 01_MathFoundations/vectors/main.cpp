//
// Created by specktro on 17/09/25.
//
#include <iostream>
#include "vector2d.h"

int main() {
    std::cout << "Vector2D Test Program" << std::endl;

    Vector2D v1(3.0f, 4.0f);
    Vector2D v2(1.0f, 2.0f);

    std::cout << "v1: (" << v1.getX() << ", " << v1.getY() << ")" << std::endl;
    std::cout << "v2: (" << v2.getX() << ", " << v2.getY() << ")" << std::endl;

    // We'll test the operations as we implement them

    return 0;
}