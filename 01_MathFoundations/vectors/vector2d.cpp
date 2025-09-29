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

float Vector2D::angleBetween(const Vector2D& other) const {
    // Handle zero-length vectors to avoid division by zero
    float thisLength = this->length();
    float otherLength = other.length();

    if (thisLength == 0.0f || otherLength == 0.0f) {
        return 0.0f;  // Return 0 if either vector has no length
    }

    // Formula: cos(angle) = (a · b) / (|a| * |b|)
    float dotProduct = this->dot(other);
    float cosAngle = dotProduct / (thisLength * otherLength);

    // Clamp to [-1, 1] to handle floating point errors
    if (cosAngle > 1.0f) cosAngle = 1.0f;
    if (cosAngle < -1.0f) cosAngle = -1.0f;

    // acos gives us the angle in radians
    return std::acos(cosAngle);
}

Vector2D Vector2D::scale(float factor) const {
    return {x * factor, y * factor};
}

// Static functions - implemented WITHOUT 'static' keyword
Vector2D Vector2D::lerp(const Vector2D& a, const Vector2D& b, float t) {
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;

    return Vector2D(
        a.x + t * (b.x - a.x),
        a.y + t * (b.y - a.y)
    );
}

Vector2D Vector2D::fromAngle(float angleRadians) {
    return Vector2D(
        std::cos(angleRadians),
        std::sin(angleRadians)
    );
}