#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "Enemy.hpp"
class Monster :public Enemy {
private:
	std::string ability;
public:
	Monster(const std::string& name, int health, int damage, const std::string& ability);
	void attack() const override;
	void displayinfo()const override;
};
#endif // !MONSTER_HPP
