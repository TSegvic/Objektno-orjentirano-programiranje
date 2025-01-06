#include "Boss.hpp"
#include "Monster.hpp"
#include <vector>
#include <memory>
#include <iostream>
int main() {
	std::vector<std::unique_ptr<Enemy>> enemies;
    try {
        enemies.push_back(std::make_unique<Boss>("Dark Lord", 500, 75, "Shadow Sword"));
        enemies.push_back(std::make_unique<Monster>("Goblin", 100, 15, "Poison Attack"));
        enemies.push_back(std::make_unique<Boss>("Dragon King", 800, 120, "Fire Breath"));
        enemies.push_back(std::make_unique<Monster>("Slime", 50, 5, "Acid Splash"));
        enemies.push_back(std::make_unique<Boss>("", 300, 50, "Flame Bow"));
        enemies.push_back(std::make_unique<Monster>("Wolf", -100, 20, "Bite"));
    }
    catch (const std::invalid_argument e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    for (const auto& enemy : enemies) {
        enemy->attack();
        enemy->displayinfo();
    }
    return 0;
}