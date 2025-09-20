//
// Created by specktro on 18/09/25.
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Challenge 1: Smart Pointers
class GameEntity {
private:
    std::string name;
    int health;

public:
    GameEntity(const std::string& name, int health) : name(name), health(health) {
        std::cout << "Created: " << name << std::endl;
    }

    ~GameEntity() {
        std::cout << "Destroyed: " << name << std::endl;
    }

    void takeDamage(int damage) { health -= damage; }
    int getHealth() const { return health; }
    const std::string& getName() const { return name; }
};

std::unique_ptr<GameEntity> createPlayer(const std::string& name) {
    return std::make_unique<GameEntity>(name, 100);
}

// Challenge 2: Move Semantics
class LargeResource {
private:
    std::vector<int> data;

public:
    // Normal constructor
    LargeResource(size_t size) : data(size, 42) {
        std::cout << "Created resource with " << size << " elements" << std::endl;
    }

    LargeResource(LargeResource&& other) noexcept {
        data = std::move(other.data);
        std::cout << "Moved resource with " << data.size() << " elements" << std::endl;
    }

    size_t size() const { return data.size(); }
};

// Challenge 3: Auto and Range-based for loops
void printVector(const std::vector<int>& vec) {
    std::cout << "Vector contents: ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Testing Smart Pointers ===" << std::endl;
    {
        auto player = createPlayer("Hero");
        std::cout << "Player: " << player->getName()
                  << ", Health: " << player->getHealth() << std::endl;
        player->takeDamage(25);
        std::cout << "After damage: " << player->getHealth() << std::endl;
    } // player automatically destroyed here

    std::cout << "\n=== Testing Move Semantics ===" << std::endl;
    {
        LargeResource resource1(1000);
        LargeResource resource2 = std::move(resource1);  // Move constructor called
        std::cout << "resource1 size: " << resource1.size() << std::endl;  // Should be 0
        std::cout << "resource2 size: " << resource2.size() << std::endl;  // Should be 1000
    }

    std::cout << "\n=== Testing Auto and Range-based For ===" << std::endl;
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        printVector(numbers);
    }

    return 0;
}