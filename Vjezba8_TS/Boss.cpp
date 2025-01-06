#include "Boss.hpp"

Boss::Boss(const std::string& name, int health, int damage, const std::string& weapon):Enemy(name,health,damage),weapon(weapon)
{
	if (weapon.empty())
	{
		throw std::invalid_argument("Netocni naziv(ne smije bit prazno)");
	}
}

void Boss::attack() const
{
	std::cout << name << " napada s " << weapon << " i radi " << damage << " stete igracu"<<std::endl;
}

void Boss::displayinfo() const
{
	std::cout << "Boss: " << name << " ima " << health << " zivota , a napravio je  " << damage << " stete igracu s " << weapon << std::endl;
}
