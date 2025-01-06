#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <stdexcept>
#include <iostream>
class Enemy{
protected:
	std::string name;
	int health;
	int damage;
public:
	Enemy(const std::string& name, int health, int damage);
	virtual ~Enemy() = default;
	virtual void attack() const = 0;
	virtual void displayinfo() const = 0;
};
#endif