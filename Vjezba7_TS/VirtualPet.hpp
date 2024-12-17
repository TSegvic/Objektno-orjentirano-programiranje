#ifndef VIRTUALPET_HPP
#define VIRTUALPET_HPP
#include<string>
#include <iostream>
class VirtualPet {
private:
	std::string name;
	std::string kind;
	int hunger;
	int happy;
	bool awake;
	int foodEaten;
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
	int getFoodEaten();
	void print();
	bool operator==(const VirtualPet& other)const;
	bool operator!=(const VirtualPet& other)const;
	VirtualPet& operator=(const VirtualPet& other);
	VirtualPet& operator++();
	VirtualPet operator++(int);
	bool operator<(const VirtualPet& other)const;
	bool operator>(const VirtualPet& other)const;
	bool operator<=(const VirtualPet& other)const;
	bool operator>=(const VirtualPet& other)const;
	friend std::ostream& operator<<(std::ostream& os,const VirtualPet& other);
};
#endif