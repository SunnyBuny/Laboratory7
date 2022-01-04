#include <iostream>


int main() {
	int n;
	std::cout << "Enter tne natural number:  ";
	std::cin >> n;
	int result[40];
	int i = 0;
	while (n != 0) {
		result[i] = n % 3;
		if (n % 3 == 0) { result[i] = 3; }// если в обычной троичной системе мы бы писали 0, то в нашей будем писать 3
		i++;
		n /= 3;
	}

	for (int j = i - 1; j >= 0; j--) {
		std::cout << result[j];
	}
}