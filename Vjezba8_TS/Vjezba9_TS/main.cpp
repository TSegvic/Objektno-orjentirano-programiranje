#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
template <typename TYPE>
TYPE mini(TYPE a, TYPE b)
{
	if (a < b)
		return a;
	else
		return b;
}
template<typename T>
class Skup {
private:
	std::vector<T> a;
public:
	void add(const T& element)
	{
		if (std::find(a.begin(), a.end(), element) == a.end())
			a.push_back(element);
	}
	void sub(const T& element)
	{
		a.erase(std::remove(a.begin(), a.end(), element), a.end());
	}
	bool contains(const T& element)
	{
		if (std::find(a.begin(), a.end(), element) != a.end())
			return true;
		else
			return false;
	}
	void print()
	{
		for (const auto& element : a) {
			std::cout << "Element: " << element << std::endl;
		}
	}
};
int main()
{
	int a, b;
	a = 1;
	b = 5;
	std::cout << mini(a, b)<<std::endl;
	Skup<int> d;
	d.add(a);
	d.add(b);
	d.print();
	std::cout << std::boolalpha << d.contains(4) << std::endl;;
	d.sub(1);
	d.print();
	

}