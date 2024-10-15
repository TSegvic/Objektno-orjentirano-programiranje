#include <iostream>
#include <iomanip>
#include <string>
int main()
{
	std::string b;
	std::getline(std::cin,b);
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::noboolalpha << flag << std::endl;
	int a = 10;
	std::cout.width(10);
	std::cout << "hex " << std::hex << std::left <<std::uppercase << a << std::endl;
	std::cout.width(10);
	std::cout << "dec " << std::dec << std::right << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double pi = 3.141592;
	std::cout << "pi = " << std::scientific<< std::nouppercase;
	std::cout << std::setprecision(7) << std::setw(20) << std::setfill('0');
	std::cout << pi << std::endl;
}