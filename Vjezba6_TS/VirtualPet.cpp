#include "VirtualPet.hpp"
#include <iostream>

	VirtualPet::VirtualPet(std::string n, std::string k) {
		name = n;
		kind = k;
		hunger = 50;
		happy = 50;
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
	void VirtualPet::print()
	{
		std::cout << "Ljubimac " << name << " vrste: " << kind << " ( Glad: " << hunger << " Sreca: " << happy << " je budan :" << awake << ")" << endl;
	}
};