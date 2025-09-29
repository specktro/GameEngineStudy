//
// Created by specktro on 25/09/25.
//

#include <iostream>
#include "../vectors/vector2d.h"

class BouncingBall {
private:
    Vector2D position;
    Vector2D velocity;
    Vector2D gravity;
    float radius;
    float bounceFactor;  // Energy retention after bounce (0.0 to 1.0)

    // World boundaries
    float worldWidth, worldHeight;

public:
    BouncingBall(Vector2D startPos, Vector2D startVel, float r = 10.0f)
        : position(startPos), velocity(startVel), radius(r),
          gravity(0, -0.2f), bounceFactor(0.8f),
          worldWidth(800), worldHeight(600) {}

    void update() {
        // Apply physics
        velocity = velocity + gravity;  // Gravity affects velocity
        position = position + velocity; // Velocity affects position

        // Bounce off walls
        if (position.getX() - radius < 0 || position.getX() + radius > worldWidth) {
            // TODO: Reverse X velocity and apply bounce factor
            // TODO: Keep ball inside bounds
        }

        if (position.getY() - radius < 0 || position.getY() + radius > worldHeight) {
            // TODO: Reverse Y velocity and apply bounce factor
            // TODO: Keep ball inside bounds
        }
    }

    void printEnergy() const {
        float kineticEnergy = 0.5f * (velocity.getX() * velocity.getY() + velocity.getX() * velocity.getY());
        std::cout << "Kinetic Energy: " << kineticEnergy << std::endl;
    }

    void printStatus(int frame) const {
        std::cout << "Frame " << frame
                  << ": Pos(" << position.getX() << ", " << position.getY() << ")"
                  << " Vel(" << velocity.getX() << ", " << velocity.getY() << ")"
                  << " Speed: " << velocity.length() << std::endl;
    }
};

// Add to your main function or create a separate test
void testDotProduct() {
    Vector2D forward(1, 0);      // Facing right
    Vector2D playerDir(0.7f, 0.7f);  // 45 degrees up-right

    float dot = forward.dot(playerDir.normalize());
    std::cout << "Dot product: " << dot << std::endl;

    // Dot product tells us:
    // 1.0  = same direction
    // 0.0  = perpendicular
    // -1.0 = opposite direction

    if (dot > 0.5f) {
        std::cout << "Player is generally facing forward" << std::endl;
    } else if (dot < -0.5f) {
        std::cout << "Player is generally facing backward" << std::endl;
    } else {
        std::cout << "Player is facing sideways" << std::endl;
    }
}

// int main() {
//     BouncingBall ball(Vector2D(100, 500), Vector2D(3, 2));
//
//     // Simulate 100 frames
//     for (int frame = 0; frame < 100; ++frame) {
//         ball.update();
//         if (frame % 10 == 0) {  // Print every 10th frame
//             ball.printStatus(frame);
//             ball.printEnergy();
//         }
//     }
//
//     testDotProduct();
//
//     return 0;
// }