//
// Created by specktro on 17/09/25.
//
#include <iostream>
#include "vector2d.h"
#include "vector3d.h"

// Add to your main.cpp or create a separate test file
void testAdvancedVectorOperations() {
    std::cout << "=== Testing Advanced Vector Operations ===" << std::endl;

    // Test angleBetween
    Vector2D right(1, 0);
    Vector2D up(0, 1);
    Vector2D diagonal(1, 1);

    std::cout << "Angle between right and up: "
              << right.angleBetween(up) << " radians" << std::endl;  // Should be ~1.57 (π/2)
    std::cout << "Angle between right and diagonal: "
              << right.angleBetween(diagonal) << " radians" << std::endl;  // Should be ~0.785 (π/4)

    // Test lerp
    Vector2D start(0, 0);
    Vector2D end(100, 100);

    Vector2D quarter = Vector2D::lerp(start, end, 0.25f);
    Vector2D half = Vector2D::lerp(start, end, 0.5f);
    Vector2D threeQuarter = Vector2D::lerp(start, end, 0.75f);

    std::cout << "Lerp 25%: (" << quarter.getX() << ", " << quarter.getY() << ")" << std::endl;
    std::cout << "Lerp 50%: (" << half.getX() << ", " << half.getY() << ")" << std::endl;
    std::cout << "Lerp 75%: (" << threeQuarter.getX() << ", " << threeQuarter.getY() << ")" << std::endl;

    // Test fromAngle
    Vector2D east = Vector2D::fromAngle(0);           // Should be (1, 0)
    Vector2D north = Vector2D::fromAngle(1.5708f);    // π/2, should be (0, 1)
    Vector2D west = Vector2D::fromAngle(3.14159f);    // π, should be (-1, 0)

    std::cout << "East: (" << east.getX() << ", " << east.getY() << ")" << std::endl;
    std::cout << "North: (" << north.getX() << ", " << north.getY() << ")" << std::endl;
    std::cout << "West: (" << west.getX() << ", " << west.getY() << ")" << std::endl;
}

void testBasic3DOperations() {
    std::cout << "=== Basic 3D Vector Operations ===" << std::endl;

    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);

    Vector3D sum = v1 + v2;
    std::cout << "Sum: "; sum.print();

    float dot = v1.dot(v2);
    std::cout << "Dot product: " << dot << std::endl;

    float distance = v1.distanceTo(v2);
    std::cout << "Distance: " << distance << std::endl;
}

void testCrossProduct() {
    std::cout << "\n=== Cross Product Examples ===" << std::endl;

    // Standard basis vectors
    Vector3D xAxis(1, 0, 0);
    Vector3D yAxis(0, 1, 0);
    Vector3D zAxis(0, 0, 1);

    // X cross Y = Z
    Vector3D result1 = xAxis.cross(yAxis);
    std::cout << "X cross Y = "; result1.print();  // Should be (0, 0, 1)

    // Y cross X = -Z (order matters!)
    Vector3D result2 = yAxis.cross(xAxis);
    std::cout << "Y cross X = "; result2.print();  // Should be (0, 0, -1)

    // Y cross Z = X
    Vector3D result3 = yAxis.cross(zAxis);
    std::cout << "Y cross Z = "; result3.print();  // Should be (1, 0, 0)
}

void testSurfaceNormal() {
    std::cout << "\n=== Surface Normal Calculation ===" << std::endl;

    // Triangle in 3D space
    Vector3D pointA(0, 0, 0);
    Vector3D pointB(1, 0, 0);
    Vector3D pointC(0, 1, 0);

    // Two edges of the triangle
    Vector3D edge1 = pointB - pointA;  // (1, 0, 0)
    Vector3D edge2 = pointC - pointA;  // (0, 1, 0)

    // Normal is perpendicular to both edges
    Vector3D normal = edge1.cross(edge2).normalize();
    std::cout << "Triangle normal: "; normal.print();  // Should be (0, 0, 1)

    std::cout << "This normal tells us the triangle faces the +Z direction" << std::endl;
}

void testCameraLookDirection() {
    std::cout << "\n=== Camera Coordinate System ===" << std::endl;

    // Camera looking down -Z axis (standard in OpenGL)
    Vector3D cameraForward(0, 0, -1);
    Vector3D worldUp(0, 1, 0);

    // Calculate camera's right vector
    Vector3D cameraRight = cameraForward.cross(worldUp).normalize();
    std::cout << "Camera right: "; cameraRight.print();

    // Calculate camera's actual up vector (perpendicular to forward and right)
    Vector3D cameraUp = cameraRight.cross(cameraForward).normalize();
    std::cout << "Camera up: "; cameraUp.print();

    std::cout << "These three vectors form the camera's coordinate system!" << std::endl;
}

int main() {
    testAdvancedVectorOperations();

    testBasic3DOperations();
    testCrossProduct();
    testSurfaceNormal();
    testCameraLookDirection();

    return 0;
}