#include "VirtualPet.hpp"
#include "Owner.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Owner happiestOwner(std::vector<Owner> owners)
{
	std::vector<int> brojsretnih;
	for (int i = 0;i < owners.size();i++) {
		int brojs = 0;
		for (int j = 0;j < owners.at(i).getPets().size();j++)
		{
			if (owners.at(i).getPets().at(j).getHappines())
				brojs++;
		}
		brojsretnih.push_back(brojs);
	}
	int naj = *std::max_element(brojsretnih.begin(), brojsretnih.end());
	return owners.at(naj);
}
int main(void)
{
	int numvlas, numakcije, numpets;
	std::cout << "Unesite broj vlasnika: ";
	std::cin >> numvlas;
	std::cout << "Unesite broj ljubimaca po vlasniku: ";
	std::cin >> numpets;
	std::cout << "Unesite broj akcija po ljubimcu: ";
	std::cin >> numakcije;
	std::vector<Owner> owners;
	for (int i = 0;i < numvlas;i++)
	{
		std::string ime;
		std::cout << "Unesite ime " << i + 1 << " vlasnika";
		std::cin >> ime;
		Owner owner(ime);
		for (int j = 0;j < numpets;j++)
		{
			std::string imelj, tip;
			std::cout << "Unesite ime " << j + 1 << " ljubimca";
			std::cin >> imelj;
			std::cout << "Unesite vrstu ljubimca";
			std::cin >> tip;
			VirtualPet pet(imelj, tip);
			owner.addPet(pet);
		}
		owners.push_back(std::move(owner));
	}
	for (auto& owner : owners) {
		owner.performactions(numakcije / 2, numakcije / 2);
		owner.print();
	}
	happiestOwner(owners).print();
	return 0;
}