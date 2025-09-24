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

Vector2D Vector2D::normalize() const {
    float len = length();

    if (len == 0) {
        return {0, 0};  // Avoid division by zero
    }

    return {x / len, y / len};
}

float Vector2D::distanceTo(const Vector2D& other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

Vector2D Vector2D::perpendicular() const {
    return {y, -x};
}

// TODO: Implement the following method
float Vector2D::angleBetween(const Vector2D& other) const {
    return 0.0f;
}

Vector2D Vector2D::scale(float factor) const {
    return {x * factor, y * factor};
}

// Static utility methods
// TODO: Implement the following method
static Vector2D lerp(const Vector2D& a, const Vector2D& b, float t) {
    return {0, 0};
}

// TODO: Implement the following method
static Vector2D fromAngle(float angleRadians) {
    return {0, 0};
}
