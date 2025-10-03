//
// Created by specktro on 02/10/25.
//

#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
private:
    float x, y, z;

public:
    // Constructors
    Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    // Basic operations (similar to Vector2D)
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(float scalar) const;  // Scale

    // Vector operations
    float length() const;
    float dot(const Vector3D& other) const;
    Vector3D normalize() const;
    float distanceTo(const Vector3D& other) const;

    // NEW - The star of 3D: Cross Product!
    Vector3D cross(const Vector3D& other) const;

    // Getters
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    // Utility
    void print() const;
};

#endif