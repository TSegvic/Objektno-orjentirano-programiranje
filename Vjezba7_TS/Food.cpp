#include"Food.hpp"
#include<iostream>
int Food::counter = 0;
Food::Food()
{
	++counter;
}
Food::~Food()
{
	--counter;
}

 void Food::increase(int kol)
{
	 counter += kol;
}
  void Food::decrease(int kol)
{
	if (counter - kol < 0)
		counter = 0;
	else
		counter = counter - kol;
}
 void Food::print()
{
	std::cout << "Kolicina hrane iznosi: " << counter << " porcija" << std::endl;
}
int get_counter() {
	return Food::counter;
}