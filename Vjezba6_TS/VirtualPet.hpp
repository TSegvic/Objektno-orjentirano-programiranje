#ifndef VIRTUALPET_HPP
#define VIRTUALPET_HPP
#include<string>
class VirtualPet {
private:
	std::string name;
	std::string kind;
	int hunger;
	int happy;
	bool awake;
public:
	VirtualPet(std::string n, std::string k);
	VirtualPet(VirtualPet& other);
	void eat();
	void sleep();
	void play();
	const std::string getName();
	const std::string getKind();
	int getHappines();
	int getHunger();
	bool getAwake();
	void print();
};
#endif