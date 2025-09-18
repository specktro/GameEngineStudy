#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
private:
    float x, y;

public:
    Vector2D(float x = 0.0f, float y = 0.0f);

    // TODO: We'll implement these step by step
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    float length() const;
    float dot(const Vector2D& other) const;

    // Getters for testing
    float getX() const { return x; }
    float getY() const { return y; }
};

#endif