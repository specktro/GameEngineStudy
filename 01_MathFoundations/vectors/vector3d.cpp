//
// Created by specktro on 02/10/25.
//

#include "vector3d.h"
#include <cmath>
#include <iostream>

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vector3D Vector3D::operator*(float scalar) const {
    return {scalar * x, scalar * y, scalar * z};
}

float Vector3D::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

float Vector3D::dot(const Vector3D& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3D Vector3D::normalize() const {
    float len = length();

    if (len == 0) {
        return {0, 0, 0};
    }

    return {x / len, y / len, z / len};
}

float Vector3D::distanceTo(const Vector3D& other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
}

// THE NEW ONE - Cross Product
Vector3D Vector3D::cross(const Vector3D& other) const {
    // Formula:
    // result.x = a.y * b.z - a.z * b.y
    // result.y = a.z * b.x - a.x * b.z
    // result.z = a.x * b.y - a.y * b.x
    return {
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    };
}

void Vector3D::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}