//
// Created by specktro on 20/10/25.
//

#include "matrix3x3.h"
#include <cmath>
#include <iostream>
#include <iomanip>

// Identity matrix construct
Matrix3x3::Matrix3x3() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

// Constructor with all values
Matrix3x3::Matrix3x3(float m00, float m01, float m02,
                     float m10, float m11, float m12,
                     float m20, float m21, float m22) {
    m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
    m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
}

// Element access
float Matrix3x3::get(int row, int col) const {
    return m[row][col];
}

void Matrix3x3::set(int row, int col, float value) {
    m[row][col] = value;
}

// Matrix addition
Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = m[i][j] + other.m[i][j];
        }
    }
    return result;
}

// Matrix substraction
Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = m[i][j] - other.m[i][j];
        }
    }
    return result;
}

// CRITICAL: Matrix multiplication
Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = 0.0f;

            for (int k = 0; k < 3; k++) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}

// Scalar multiplication
Matrix3x3 Matrix3x3::operator*(float scalar) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = m[i][j] * scalar;
        }
    }
    return result;
}

// Transform a 3D vector
Vector3D Matrix3x3::operator*(const Vector3D &vec) const {
    return Vector3D(
        m[0][0] * vec.getX() + m[0][1] * vec.getY() + m[0][2] * vec.getZ(),
        m[1][0] * vec.getX() + m[1][1] * vec.getY() + m[1][2] * vec.getZ(),
        m[2][0] * vec.getX() + m[2][1] * vec.getY() + m[2][2] * vec.getZ()
    );
}

Vector2D Matrix3x3::transformPoint(const Vector2D &point) const {
    float x = m[0][0] * point.getX() + m[0][1] * point.getY() + m[0][2];
    float y = m[1][0] * point.getX() + m[1][1] * point.getY() + m[1][2];
    return Vector2D(x, y);
}

// Transform 2D vector (without translation)
Vector2D Matrix3x3::transformVector(const Vector2D &vec) const {
    float x = m[0][0] * vec.getX() + m[0][1] * vec.getY();
    float y = m[1][0] * vec.getX() + m[1][1] * vec.getY();
    return Vector2D(x, y);
}

// Transpose (swap rows and columns)
Matrix3x3 Matrix3x3::transpose() const {
    Matrix3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = m[j][i];
        }
    }
    return result;
}

// Determinant (used for inverse)
float Matrix3x3::determinant() const {
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
         - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
         + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

// Matrix inverse (simplified version)
Matrix3x3 Matrix3x3::inverse() const {
    float det = determinant();

    if (std::abs(det) < 0.00001f) {
        std::cerr << "Warning: Matrix is not invertible (det ≈ 0)" << std::endl;
        return Matrix3x3::identity();
    }

    Matrix3x3 result;

    // Calculate cofactor matrix and transpose (adjugate)
    result.m[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
    result.m[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
    result.m[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;

    result.m[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
    result.m[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    result.m[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;

    result.m[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
    result.m[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
    result.m[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;

    return result;
}

// Pretty print
void Matrix3x3::print() const {
    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < 3; i++) {
        std::cout << "[ ";
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(8) << m[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}

// Factory methods
Matrix3x3 Matrix3x3::identity() {
    return Matrix3x3();
}

Matrix3x3 Matrix3x3::zero() {
    return Matrix3x3(0, 0, 0,
                     0, 0, 0,
                     0, 0, 0);
}

Matrix3x3 Matrix3x3::scale(float sx, float sy) {
    return Matrix3x3(
        sx,  0,   0,
        0,   sy,  0,
        0,   0,   1
    );
}

Matrix3x3 Matrix3x3::rotation(float angleRadians) {
    float c = std::cos(angleRadians);
    float s = std::sin(angleRadians);

    return Matrix3x3(
        c,  -s,  0,
        s,   c,  0,
        0,   0,  1
    );
}

Matrix3x3 Matrix3x3::translation(float tx, float ty) {
    return Matrix3x3(
        1,  0,  tx,
        0,  1,  ty,
        0,  0,  1
    );
}

Matrix3x3 Matrix3x3::shear(float shx, float shy) {
    return Matrix3x3(
        1,    shx,  0,
        shy,  1,    0,
        0,    0,    1
    );
}