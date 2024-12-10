#include"Owner.hpp"
#include<iostream>
#include<algorithm>
#include<random>

	Owner::Owner(std::string n, std::vector<VirtualPet>p)
	{
		name = n;
		pets = p;
	}
	Owner::Owner(Owner& other)
	{
		name = other.name;
		pets = other.pets;
	}
	void Owner::addPet(VirtualPet pet)
	{
		pets.push_back(pet);
	}
	void Owner::performactions(int feedc, int playc)
	{
		std::random_device rd;
		std::mt19937 gen(rd);
		std::uniform_int_distribution<int> dist(0, 1);
		for (auto pet : pets)
		{
			for (int i = 0; i < feedc + playc; i++)
			{
				if (dist(gen))
					pet.play();
				else
					pet.eat();
			}
		}
	}
	const std::vector<VirtualPet> Owner::getPets()
	{
		return pets;
	}
	const std::string Owner::getName()
	{
		return name;
	}
	void Owner::print()
	{
		std::cout << "Owner :" << name << std::endl;
		for (const VirtualPet pet : pets)
		{
			pet.print();
		}
	}
