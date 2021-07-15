// codewars.com.cpp : Defines the entry point for the application.
//

#include "codewars.com.h"

int get_sum2(int a, int b)
{
	int sum = a;
	if (a < b) {
		for (int i = a + 1; i <= b; i++) {
			sum += i;
		}
	}
	else {
		for (int i = a - 1; i >= b; i--) {
			sum += i;
		}
	}

	return sum;
}

// Быстрая реализация без цикла
int get_sum(int a, int b) {
	int n = (a > b? a - b: b - a) + 1;
	return n * (a + b) / 2;
}


int main()
{
	std::cout << get_sum(5, -1);
	return 0;
}
