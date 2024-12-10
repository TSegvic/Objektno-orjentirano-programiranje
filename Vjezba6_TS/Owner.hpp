#ifndef OWNER_HPP
#define OWNER_HPP
#include "VirtualPet.hpp"
#include <vector>
#include <string>
class Owner {
private:
	std::string name;
	std::vector<VirtualPet> pets;
public:
	Owner(std::string n, std::vector<VirtualPet>p);
	
	Owner(Owner& other);
	
	void addPet(VirtualPet pet);
	
	void performactions(int feedc, int playc);
	
	const std::vector<VirtualPet> getPets();
	const std::string getName();
	
	void print()
};
#endif