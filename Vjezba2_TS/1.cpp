#include<iostream>
using namespace std;
typedef struct
{
	int *a;
	int logicka;
	int fizicka;
	/*vektor vector_new()
	{

	}
	void vector_delete()
	{

	}
	vektor vector_push_back()
	{

	}
	vektor vector_pop_back()
	{

	}
	int vector_front()
	{
		return a[0];
	}
	int vector_back()
	{
		return a[logicka];
	}
	int vector_size()
	{
		return logicka;
	}*/
}vektor;
void racun(int a[],int n, int& b, int& c)
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
	racun(a,10, b, c);
	cout << b << endl << c;
	cout << endl <<a[5];
}