//
// Created by specktro on 17/09/25.
//
#include "vector2d.h"
#include <cmath>

Vector2D::Vector2D(float x, float y) : x(x), y(y) {
    // Constructor implementation
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return {x + other.x, y + other.y};
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return {x - other.x, y - other.y};
}

float Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

float Vector2D::dot(const Vector2D& other) const {
    return x * other.x + y * other.y;
}