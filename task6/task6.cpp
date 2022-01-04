#include <iostream>

int sum(int n) {// сумма цифр в числе
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}


int main() {
	int t;// количество наборов входных данных
	std::cout << "Enter the amount of input data\n";
	while (!(std::cin >> t) || t < 0) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}

	for (int i = 0; i < t; i++) {
		int n;
		int temp = 0;
		std::cout << "Enter tne number : " << std::endl;
		while (!(std::cin >> n) || n < 0) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		for (int i = 1; i < n; i++) {
			if (sum(i) > sum(i + 1)) {
				temp++;
			}
		}
		std::cout << temp;
	}
}
