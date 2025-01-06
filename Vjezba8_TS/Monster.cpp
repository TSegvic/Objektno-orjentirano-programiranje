#include "Monster.hpp"

Monster::Monster(const std::string& name, int health, int damage, const std::string& ability):Enemy(name,health,damage),ability(ability)
{
	if (ability.empty())
		throw std::invalid_argument("Netocni naziv(ne smije bit prazno)");
}

void Monster::attack() const
{
	std::cout << name << " napada s " << ability << " i radi " << damage << " stete igracu"<<std::endl;
}

void Monster::displayinfo() const
{
	std::cout << "Enemy: " << name << " ima " << health << " zivota , a napravio je  " << damage << " stete igracu s " << ability << std::endl;
}
