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
static void increase(int kol)
{
	 counter += kol;
}
static void decrease(int kol)
{
	if (counter - kol < 0)
		counter = 0;
	else
		counter = counter - kol;
}
static void print()
{
	std::cout << "Kolicina hrane iznosi: " << counter << " porcija" << std::endl;
}
int get_counter() {
	return Food::counter;
}