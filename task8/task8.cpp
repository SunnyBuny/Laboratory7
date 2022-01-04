#include <iostream>
#include <string>
using namespace std;

std::string convert(int n) { //перевод в двоичную систему
	std::string n1;
	int i = 0;
	while (n != 0) {
		if (n % 2 == 0) {
			n1.insert(0, 1, '0');
			n /= 2;
		}
		else {
			n1.insert(0, 1, '1');
			n /= 2;
		}
		i++;
	}

	return n1;
}

bool only1and0(std::string a) {	//проверка на то, что число состоит только из 1 и 0, иначе оно не может быть двудесятичным
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != '1' && a[i] != '0') {
			return false;
		}
	}
	return true;
}


std::string inString(int a) { //перевод в строку
	std::string a1;
	while (a) {
		a1.insert(0, 1, a % 10 + '0');
		a = a / 10;
	}
	return a1;
}

bool compare(std::string a1, std::string a2) { //проверка на двудесятичность
	bool equal = 1;
	for (int i = 0; i < a1.length(); i++) {
		equal = 1;
		for (int j = 0; j < a2.length(); j++) {
			if (a1[i + j] != a2[j]) {
				equal = 0;
				break;
			}
		}
		if (equal) {
			return equal;
		}
	}
	return equal;
}

int main() {


	int n, a = 1;
	int i = 0;// счётчик 
	std::cout << "The program prints the n-th smallest two-decimal number" << std::endl << "Enter n: ";
	std::cin >> n;
	while (i < n) {
		std::string a1 = inString(a);
		if (only1and0(a1) && compare(convert(a), a1)) {
			i++;
		}
		a++;
	}
	a--;
	std::cout << "The smallest two-decimal number: " << a << std::endl;
}
