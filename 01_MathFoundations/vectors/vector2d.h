#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
private:
    float x, y;

public:
    Vector2D(float x = 0.0f, float y = 0.0f);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    float length() const;
    float dot(const Vector2D& other) const;

    Vector2D normalize() const;           // Unit vector (length = 1)
    float distanceTo(const Vector2D& other) const;  // Distance between points
    Vector2D perpendicular() const;       // 90-degree rotation
    float angleBetween(const Vector2D& other) const;  // Angle in radians
    Vector2D scale(float factor) const;   // Multiply by scalar

    // Static functions - declared WITH 'static'
    static Vector2D lerp(const Vector2D& a, const Vector2D& b, float t);
    static Vector2D fromAngle(float angleRadians);

    // Getters for testing
    float getX() const { return x; }
    float getY() const { return y; }
};

#endif