#ifndef BOSS_HPP
#define BOSS_HPP
#include "Enemy.hpp"
class Boss :public Enemy {
private:
	std::string weapon;
public:
	Boss(const std::string& name, int health, int damage, const std::string& weapon);
	void attack() const override;
	void displayinfo() const override;
};
#endif // !BOSS_HPP
