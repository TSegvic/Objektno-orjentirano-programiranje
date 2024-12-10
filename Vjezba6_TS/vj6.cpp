#include <iostream>
#include <random>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class VirtualPet {
private:
	string name;
	string kind;
	int hunger;
	int happy;
	bool awake;
public:
	VirtualPet(string n, string k) {
		name = n;
		kind = k;
		hunger = 50;
		happy = 50;
		awake = true;
	}
	VirtualPet(VirtualPet& other)
	{
		name = other.name;
		kind = other.kind;
		hunger = other.hunger;
		happy = other.happy;
		awake = other.awake;
	}
	void eat()
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
	void sleep()
	{
		if (hunger > 30)
			cout << name << " je gladan ne moze spavat";
		while(hunger < 30)
		{
			awake = false;
			hunger = min(100,hunger + 10);
			happy = min(100, happy + 15);
		}
		awake = true;
	}
	void play()
	{
		if (awake)
		{
			hunger = min(100, hunger + 10);
			happy = min(100, happy + 15);
		}
	}
	const string getName()
	{
		return name;
	}
	const string getKind()
	{
		return kind;
	}
	int getHappines()
	{
		return happy;
	}
	int getHunger()
	{
		return hunger;
	}
	bool getAwake()
	{
		return awake;
	}
	void print()
	{
		cout << "Ljubimac " << name << " vrste: " << kind << " ( Glad: " << hunger << " Sreca: " << happy << " je budan :" << awake << ")" << endl;
	}
};
int main()
{
	VirtualPet mate("Mate", "zebra");
	mate.eat();
	mate.sleep();
	mate.play();
	mate.eat();
	mate.sleep();
}