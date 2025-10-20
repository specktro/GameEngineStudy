//
// Created by specktro on 02/10/25.
//

#include "vector3d.h"
#include <cmath>
#include <complex>
#include <filesystem>
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

    if (len < std::numeric_limits<float>::epsilon() * 10) {
        return {0, 0, 0};
    }

    return {x / len, y / len, z / len};
}

float Vector3D::distanceTo(const Vector3D& other) const {
    return (other - *this).length();
}

Vector3D Vector3D::cross(const Vector3D& other) const {
    return {
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    };
}

bool Vector3D::isZero() const {
    float len = length();
    return len < std::numeric_limits<float>::epsilon() * 10;
}

bool Vector3D::isNormalized() const {
    float len = length();
    return std::abs(len - 1.0f) < 0.0001f;
}

Vector3D Vector3D::reflect(const Vector3D& normal) const {
    Vector3D n = normal.normalize();
    float dotProduct = this->dot(n);
    return *this - n * (2.0f * dotProduct);
}

Vector3D Vector3D::project(const Vector3D& onto) const {
    float ontoLengthSquared = onto.dot(onto);

    if (ontoLengthSquared < 0.00001f) {
        return {0, 0, 0};
    }

    float scalar = this->dot(onto) / ontoLengthSquared;
    return onto * scalar;
}

void Vector3D::print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}