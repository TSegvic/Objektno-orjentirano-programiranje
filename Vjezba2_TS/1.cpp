#include<iostream>
using namespace std;
struct Vektor
{
	int* a;
	int logicka;
	int fizicka;
	void vector_new(int init = 4)
	{
		a = new int[init];
		logicka = 0;
		fizicka = init;
	}
	void vector_delete()
	{
		delete[] a;
		a = nullptr;
		logicka = 0;
		fizicka = 0;
	}
	void vector_push_back(int value)
	{
		if (logicka == fizicka)
		{
			fizicka *= 2;
			int* na = new int[fizicka];
			for (int i = 0;i < logicka;i++)
			{
				na[i] = a[i];
			}
			delete[] a;
			a = na;
		}
		a[logicka++] = value;
	}
	void vector_pop_back()
	{
		logicka--;
	}
	int vector_front()
	{
		return a[0];
	}
	int vector_back()
	{
		return a[logicka-1];
	}
	int vector_size()
	{
		return logicka;
	}
};
void racun(int a[], int n, int& b, int& c)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	b = min;
	c = max;
}
int& vrati(int a[], int n)
{
	return a[n];
}
int main()
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int b, c;
	vrati(a, 5)++;;
	racun(a, 10, b, c);
	cout << b << endl << c;
	cout << endl << a[5]<<endl;
	Vektor vec;
	vec.vector_new();
	vec.vector_push_back(1);
	vec.vector_push_back(2);
	vec.vector_push_back(3);
	vec.vector_push_back(4);
	vec.vector_push_back(5);

	std::cout << "Prvi element: " << vec.vector_front() << std::endl;
	std::cout << "Zadnji element: " << vec.vector_back() << std::endl;
	std::cout << "Velicina vektora: " << vec.vector_size() << std::endl;

	vec.vector_pop_back();
	std::cout << "Velicina vektora nakon pop_back: " << vec.vector_size() << std::endl;
	vec.vector_delete();
}