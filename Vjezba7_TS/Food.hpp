#ifndef FOOD_HPP
#define FOOD_HPP
class Food {
private:
	static int counter;
public:
	Food();
	~Food();
	static void increase(int kol);
	static void decrease(int kol);
	static void print();
	friend int get_counter();

};
int get_counter();
#endif // !FOOD_HPP
