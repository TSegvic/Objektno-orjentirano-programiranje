#include<iostream>
#include"Food.hpp"
#include"VirtualPet.hpp"
int main()
{
	Food hrana;
	hrana.increase(10);
	hrana.print();
	hrana.decrease(3);
	hrana.print();
	VirtualPet mate("Mate","Pas");
	VirtualPet stipe("Mate", "Pas");
	std::cout << "Pet 1: " << mate;
	mate++;
	std::cout << "Pet 1: " << mate;
	std::cout << (mate == stipe)<<std::endl;
	VirtualPet josko(mate);
	josko = stipe;
	std::cout << (josko == stipe);
	std::cout << std::endl << (mate < stipe) << std::endl << (mate > stipe) << std::endl << (mate <= stipe) << std::endl << (mate >= stipe);
}