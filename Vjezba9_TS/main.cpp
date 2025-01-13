#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <cmath>
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
template <typename T>
void sortArray(T* arr, size_t size)
{
	std::sort(arr, arr + size);
}
template<>
void sortArray<char>(char* arr, size_t size)
{
	std::sort(arr, arr + size, [](char a, char b) {
		return std::tolower(a) < std::tolower(b);
	});
}
void procesirajcetvrti(const std::string& filename, const std::string& substring)
{
	std::ifstream file(filename);
	std::vector<std::string> rijeci((std::istream_iterator<std::string>(file)), std::istream_iterator<std::string>());
	rijeci.erase(std::remove_if(rijeci.begin(), rijeci.end(), [&](const std::string rijec) {
		return rijec.find(substring) != std::string::npos;
		}), rijeci.end());
	std::transform(rijeci.begin(), rijeci.end(), rijeci.begin(), [](std::string rijec) {
		std::transform(rijec.begin(), rijec.end(), rijec.begin(), ::toupper);
		return rijec;
		});
	for (const auto& rijec : rijeci)
	{
		std::cout << rijec << " ";
	}
}
struct Point {
	double x, y;
	double udaljenost()const {
		return std::sqrt(x * x + y * y);
	}
	friend std::ostream& operator<<(std::ostream& os, const Point& point)
	{
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Point& point) {
		is >> point.x >> point.y;
		return is;
	}
};
void procesirajpeti(const std::string& filename, double target, const Point& zamjena)
{
	std::ifstream file(filename);
	std::vector<Point> points((std::istream_iterator<Point>(file)), std::istream_iterator<Point>());
	std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
		return a.udaljenost() < b.udaljenost();
		});
	std::replace_if(points.begin(), points.end(), [&](const Point& point) {
		return std::abs(point.udaljenost() - target) < 1e-9;
		}, zamjena);
	for (const auto& point : points) {
		std::cout << point << " ";
	}
	std::cout << std::endl;

}
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
	int arr[] = { 5, 2, 8, 3, 1 };
	sortArray(arr, 5);
	for (int i : arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	char charArr[] = { 'B', 'a', 'D', 'c' };
	sortArray(charArr, 4);
	for (char c : charArr) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	procesirajcetvrti("words.txt", "sub");
	Point replacementPoint{ 0, 0 };
	procesirajpeti("points.txt", 5.0, replacementPoint);
	return 0;
}