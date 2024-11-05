#include "vector.hpp"
#include <iostream>
void unosvektora(std::vector<int>& a, int brojElemanata)
{
	a.clear();
	int b;
	for (int i = 0; i < brojElemanata; i++)
	{
		std::cout << "Unesi " << i + 1 << " element vektora: ";
		std::cin >> b;
		a.push_back(b);
	}
}
void unosvektora(std::vector<int>& a, int donja, int gornja)
{
	a.clear();
	int b;
	while (true)
	{
		std::cout << "Unesi broj izmedju " << donja << ". i " << gornja << ". : ";
		std::cin >> b;
		if (b < donja || b > gornja)
			break;
		a.push_back(b);
	}
}
void ispisvektora(std::vector<int>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << i + 1 << ". element vektora je: " << a.at(i)<<std::endl;
	}
	std::cout << std::endl;
}