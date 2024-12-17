#include "VirtualPet.hpp"
#include <iostream>
#include <algorithm>

	VirtualPet::VirtualPet(std::string n, std::string k) {
		name = n;
		kind = k;
		hunger = 50;
		happy = 50;
		foodEaten = 10;
		awake = true;
	}
	VirtualPet::VirtualPet(VirtualPet& other)
	{
		name = other.name;
		kind = other.kind;
		hunger = other.hunger;
		happy = other.happy;
		awake = other.awake;
	}
	void VirtualPet::eat()
	{
		if (hunger - 10 > 0)
			hunger = hunger - 10;
		else
			hunger = 0;
		if (happy + 10 < 100)
			happy = happy + 10;
		else
			happy = 100;
		if (hunger < 30)
			sleep();
	}
	void VirtualPet::sleep()
	{
		if (hunger > 30)
			std::cout << name << " je gladan ne moze spavat";
		while (hunger < 30)
		{
			awake = false;
			hunger = std::min(100, hunger + 10);
			happy = std::min(100, happy + 15);
		}
		awake = true;
	}
	void VirtualPet::play()
	{
		if (awake)
		{
			hunger = std::min(100, hunger + 10);
			happy = std::min(100, happy + 15);
		}
	}
	const std::string VirtualPet::getName()
	{
		return name;
	}
	const std::string VirtualPet::getKind()
	{
		return kind;
	}
	int VirtualPet::getHappines()
	{
		return happy;
	}
	int VirtualPet::getHunger()
	{
		return hunger;
	}
	bool VirtualPet::getAwake()
	{
		return awake;
	}
	int VirtualPet::getFoodEaten()
	{
		return foodEaten;
	}
	void VirtualPet::print()
	{
		std::cout << "Ljubimac " << name << " vrste: " << kind << " ( Glad: " << hunger << " Sreca: " << happy << " je budan :" << awake << ")" << std::endl;
	}
	bool VirtualPet::operator==(const VirtualPet & other) const
	{
		if (name == other.name&& kind == other.kind && happy == other.happy && hunger == other.hunger && awake == other.awake)
			return true;
		else
			return false;
	}
	bool VirtualPet::operator!=(const VirtualPet & other) const
	{
		if (name == other.name&& kind == other.kind && happy == other.happy && hunger == other.hunger && awake == other.awake)
			return false;
		else
			return true;
	}

	VirtualPet & VirtualPet::operator=(const VirtualPet & other)
	{
		if (this != &other)
		{
			name = other.name;
			kind = other.kind;
			hunger = other.hunger;
			happy = other.happy;
			awake = other.awake;
			foodEaten = other.foodEaten;
		}
		return *this;
	}

	VirtualPet& VirtualPet::operator++()
	{
		++foodEaten;
		hunger = std::max(0, hunger - 10);
		return *this;
	}
	VirtualPet VirtualPet::operator++(int)
	{
		VirtualPet temp = *this;
		++(*this);
		return temp;
		
	}
	bool VirtualPet::operator<(const VirtualPet & other) const
	{
		return happy<other.happy;
	}
	bool VirtualPet::operator>(const VirtualPet & other) const
	{
		return happy > other.happy;
	}
	bool VirtualPet::operator<=(const VirtualPet & other) const
	{
		return happy <= other.happy;
	}
	bool VirtualPet::operator>=(const VirtualPet & other) const
	{
		return happy >= other.happy;
	}


std::ostream& operator<<(std::ostream& os, const VirtualPet & other)
{
	os<< "Ljubimac " << other.name << " vrste: " << other.kind << " ( Glad: " << other.hunger << " Sreca: " << other.happy << " je budan : " << std::boolalpha<<other.awake <<" i pojeo je "<<other.foodEaten<<" porcija hrane)" << std::endl;
	return os;
}
