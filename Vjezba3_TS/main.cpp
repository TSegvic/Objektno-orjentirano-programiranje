#include "vector.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> novi(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> c;
	for (int element : a)
	{
		if (find(b.begin(), b.end(), element) == b.end())
		{
			c.push_back(element);
		}

	}
	return c;
}
void operacije(std::vector<int>& a)
{
	int sum=0;
	sort(a.begin(), a.end());
	a.insert(a.begin(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		sum += a.at(i);
	}
	a.push_back(sum);
}
void brisi(std::vector<int>& a, int i)
{
	a.erase(a.begin()+i);
}
int main()
{
	std::vector<int> a, b, c;
	unosvektora(a, 5);
	unosvektora(b, 1, 10);
	ispisvektora(a);
	ispisvektora(b);
	c = novi(a, b);
	ispisvektora(c);
	operacije(a);
	ispisvektora(a);
	brisi(a, 2);
	ispisvektora(a);
	return 0;
}