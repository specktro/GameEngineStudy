//
// Created by specktro on 20/10/25.
//

#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "../vectors/vector2d.h"
#include "../vectors/vector3d.h"

class Matrix3x3 {
private:
    float m[3][3];

public:
    // Constructors
    Matrix3x3(); // Identity matrix
    Matrix3x3(float m00, float m01, float m02,
              float m10, float m11, float m12,
              float m20, float m21, float m22);

    // Element access
    float get(int row, int col) const;
    void set(int row, int col, float value);

    // Matrix operations
    Matrix3x3 operator+(const Matrix3x3& other) const;
    Matrix3x3 operator-(const Matrix3x3& other) const;
    Matrix3x3 operator*(const Matrix3x3& other) const;  // Matrix multiplication
    Matrix3x3 operator*(float scalar) const;

    // Transform vectors
    Vector3D operator*(const Vector3D& vec) const;
    Vector2D transformPoint(const Vector2D& point) const;  // For 2D points with translation
    Vector2D transformVector(const Vector2D& vec) const;   // For 2D vectors without translation

    // Matrix properties
    Matrix3x3 transpose() const;
    float determinant() const;
    Matrix3x3 inverse() const;

    // Utility
    void print() const;

    // Factory methods - common transformations
    static Matrix3x3 identity();
    static Matrix3x3 zero();
    static Matrix3x3 scale(float sx, float sy);
    static Matrix3x3 rotation(float angleRadians);
    static Matrix3x3 translation(float tx, float ty);
    static Matrix3x3 shear(float shx, float shy);
};


#endif // MATRIX3X3_H