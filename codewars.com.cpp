// codewars.com.cpp : Defines the entry point for the application.
//

#include "codewars.com.h"
#include <string>
#include <vector>
#include <algorithm>

class Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

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
	int n = (a > b ? a - b : b - a) + 1;
	return n * (a + b) / 2;
}

std::string stringify(Node* list)
{
	std::string str;
	while (list != nullptr) {
		str += std::to_string(list->data);
		str += " -> ";
		list = list->next;
	}
	str += "nullptr";
	return str;
}

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
	for (size_t i = 0; i < numbers.size() - 1; i++) {
		for (size_t j = i + 1; j < numbers.size(); j++) {
			if (numbers[i] + numbers[j] == target)
				return { i, j };
		}
	}
	return { 0, 0 };
}


int digital_root(int n)
{
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	if (sum > 9)
		sum = digital_root(sum);
	return sum;
}

class Same {
public:
	static bool comp(std::vector<int>& a, std::vector<int>& b) {
		if (a.size() != b.size())
			return false;
		std::vector<int> squars = a;
		std::for_each(squars.begin(), squars.end(), [](int& d) {d *= d; });
		for (size_t i = 0; i < b.size(); i++) {
			auto it = std::find(squars.begin(), squars.end(), b[i]);
			if(it != squars.end())
				squars.erase(it);
		}
		return squars.empty();
	}
};

/*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
Note: If the number is a multiple of both 3 and 5, only count it once. Also, if a number is negative, return 0(for languages that do have them)*/
int solution(int number)
{
	int sum = 0;
	for (int n = 3; n < number; n++) {
		if ((n % 3 == 0) || (n % 5 == 0))
			sum += n;
	}
	return sum;
}

int main()
{
	std::cout << solution(10) << std::endl;
	//Same s;
	//std::vector<int> a{ 121, 144, 19, 161, 19, 144, 19 };
	//std::vector<int> b{ 14641, 20736, 361, 25921, 361, 20736, 361, 121 };
	//std::cout << s.comp(a, b) << std::endl;
	//std::cout << digital_root(167346);
	//std::pair<int, int> pair = two_sum({ 1, 2, 3 }, 4);
	std::cout << " ";
	//std::cout << get_sum(5, -1);
	return 0;
}
