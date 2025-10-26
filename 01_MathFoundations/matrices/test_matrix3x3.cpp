#include <iostream>
#include <cmath>
#include "matrix3x3.h"

void testIdentity() {
    std::cout << "=== Test 1: Identity Matrix ===" << std::endl;
    Matrix3x3 I = Matrix3x3::identity();
    I.print();

    Vector3D v(5, 3, 1);
    Vector3D result = I * v;
    std::cout << "Identity × (5,3,1) = ";
    result.print();
    std::cout << "Expected: (5,3,1)\n" << std::endl;
}

void testMatrixMultiplication() {
    std::cout << "=== Test 2: Matrix Multiplication ===" << std::endl;

    Matrix3x3 a(1, 2, 3,
                4, 5, 6,
                7, 8, 9);

    Matrix3x3 b(9, 8, 7,
                6, 5, 4,
                3, 2, 1);

    std::cout << "Matrix A:" << std::endl;
    a.print();
    std::cout << "\nMatrix B:" << std::endl;
    b.print();

    Matrix3x3 result = a * b;
    std::cout << "\nA × B =" << std::endl;
    result.print();
    std::cout << "Expected: [30, 24, 18], [84, 69, 54], [138, 114, 90]\n" << std::endl;
}

void testRotation() {
    std::cout << "=== Test 3: Rotation ===" << std::endl;

    // 90 degree rotation
    float angle = M_PI / 2.0f;
    Matrix3x3 rot = Matrix3x3::rotation(angle);

    std::cout << "90° Rotation Matrix:" << std::endl;
    rot.print();

    Vector2D right(1, 0);
    Vector2D up = rot.transformVector(right);
    std::cout << "\nRotate (1,0) by 90° = (" << up.getX() << ", " << up.getY() << ")" << std::endl;
    std::cout << "Expected: (0, 1)\n" << std::endl;
}

void testScale() {
    std::cout << "=== Test 4: Scaling ===" << std::endl;

    Matrix3x3 scale = Matrix3x3::scale(2.0f, 3.0f);
    std::cout << "Scale Matrix (2x, 3x):" << std::endl;
    scale.print();

    Vector2D v(4, 5);
    Vector2D scaled = scale.transformVector(v);
    std::cout << "\nScale (4,5) = (" << scaled.getX() << ", " << scaled.getY() << ")" << std::endl;
    std::cout << "Expected: (8, 15)\n" << std::endl;
}

void testTranslation() {
    std::cout << "=== Test 5: Translation ===" << std::endl;

    Matrix3x3 trans = Matrix3x3::translation(10, 20);
    std::cout << "Translation Matrix (+10, +20):" << std::endl;
    trans.print();

    Vector2D point(5, 5);
    Vector2D moved = trans.transformPoint(point);
    std::cout << "\nTranslate point (5,5) = (" << moved.getX() << ", " << moved.getY() << ")" << std::endl;
    std::cout << "Expected: (15, 25)" << std::endl;

    // Important: vectors should NOT be translated!
    Vector2D vec(5, 5);
    Vector2D vecResult = trans.transformVector(vec);
    std::cout << "Translate vector (5,5) = (" << vecResult.getX() << ", " << vecResult.getY() << ")" << std::endl;
    std::cout << "Expected: (5, 5) - vectors don't translate!\n" << std::endl;
}

void testCombinedTransforms() {
    std::cout << "=== Test 6: Combined Transformations ===" << std::endl;

    // Goal: Scale by 2, then rotate 45°, then translate by (10, 10)
    Matrix3x3 scale = Matrix3x3::scale(2.0f, 2.0f);
    Matrix3x3 rotate = Matrix3x3::rotation(M_PI / 4.0f);  // 45°
    Matrix3x3 translate = Matrix3x3::translation(10.0f, 10.0f);

    // IMPORTANT: Apply in reverse order!
    // Reading right-to-left: translate * rotate * scale
    Matrix3x3 combined = translate * rotate * scale;

    std::cout << "Combined Matrix (translate ∘ rotate ∘ scale):" << std::endl;
    combined.print();

    Vector2D point(1, 0);
    Vector2D transformed = combined.transformPoint(point);
    std::cout << "\nTransform (1,0) = (" << transformed.getX() << ", " << transformed.getY() << ")" << std::endl;
    std::cout << "Expected: ~(11.41, 11.41)\n" << std::endl;
}

void testTranspose() {
    std::cout << "=== Test 7: Transpose ===" << std::endl;

    Matrix3x3 m(1, 2, 3,
                4, 5, 6,
                7, 8, 9);

    std::cout << "Original:" << std::endl;
    m.print();

    Matrix3x3 t = m.transpose();
    std::cout << "\nTransposed:" << std::endl;
    t.print();
    std::cout << "Expected: rows become columns\n" << std::endl;
}

void testInverse() {
    std::cout << "=== Test 8: Matrix Inverse ===" << std::endl;

    // Create a rotation matrix (easily invertible)
    Matrix3x3 rot = Matrix3x3::rotation(M_PI / 6.0f);  // 30°
    Matrix3x3 inv = rot.inverse();

    std::cout << "Rotation 30°:" << std::endl;
    rot.print();

    std::cout << "\nInverse:" << std::endl;
    inv.print();

    // Test: M × M⁻¹ should equal identity
    Matrix3x3 shouldBeIdentity = rot * inv;
    std::cout << "\nM × M⁻¹ (should be identity):" << std::endl;
    shouldBeIdentity.print();
    std::cout << std::endl;
}

void testGameScenario() {
    std::cout << "=== Test 9: Game Scenario - Rotating Spaceship ===" << std::endl;

    // Spaceship at origin, facing right
    Vector2D shipPos(0, 0);
    Vector2D shipFront(1, 0);  // Facing vector

    // Player presses left arrow - rotate 15° counterclockwise
    float rotationAngle = M_PI / 12.0f;  // 15 degrees
    Matrix3x3 rotation = Matrix3x3::rotation(rotationAngle);

    // Rotate the facing vector (NOT the position)
    Vector2D newFront = rotation.transformVector(shipFront);
    std::cout << "Ship now facing: (" << newFront.getX() << ", " << newFront.getY() << ")" << std::endl;

    // Move forward in new direction
    float speed = 5.0f;
    Vector2D velocity = newFront * speed;
    shipPos = shipPos + velocity;

    std::cout << "Ship moved to: (" << shipPos.getX() << ", " << shipPos.getY() << ")" << std::endl;
    std::cout << std::endl;
}

int main() {
    testIdentity();
    testMatrixMultiplication();
    testRotation();
    testScale();
    testTranslation();
    testCombinedTransforms();
    testTranspose();
    testInverse();
    testGameScenario();

    std::cout << "=== All Tests Complete ===" << std::endl;
    return 0;
}