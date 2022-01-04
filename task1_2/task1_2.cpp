#include <iostream>
#include <string>

int convertin10(std::string num14, int i, int num_10) {//аргумент num_10 передаётся нулеым для корректного перевода 
	if (num14[i] == 'a') { num_10 += 10 * pow(14, num14.size() - i - 1); }
	if (num14[i] == 'b') { num_10 += 11 * pow(14, num14.size() - i - 1); }
	if (num14[i] == 'c') { num_10 += 12 * pow(14, num14.size() - i - 1); }
	if (num14[i] == 'd') { num_10 += 13 * pow(14, num14.size() - i - 1); }
	if (num14[i] >= 48 && num14[i] <= 57) { num_10 += (num14[i] - '0') * pow(14, num14.size() - i - 1); }

	if (i == num14.size() - 1) {
		return num_10;
	}
	else {
		return convertin10(num14, i + 1, num_10);
	}

}

int convertin6(int num_10, int i, int num_6) {//аргумент num_6 передаётся нулеым для корректного перевода 

	num_6 += num_10 % 6 * pow(10, i);
	if (num_10 != 0) {
		return convertin6(num_10 / 6, i + 1, num_6);
	}
	else {
		return num_6;
	}
}
// нужно перевести числа из 14ти ричной системы счисления в 6ти ричную
int main() {
	std::string num_14;
	int num_10;
	int num_6;
	std::cout << "Enter tne number in 14" << "\n";
	bool input = true;
	while (input) {// проверка на ввод
		getline(std::cin, num_14);
		if (num_14.size() == 0 || num_14.size() > 10) {
			std::cout << "The minimum number of digits and letters is 1 and maximum is 10. Enter the number again: ";
		}
		else if (num_14.find_first_not_of("0123456789abcd") <= num_14.size()) {
			std::cout << "The number should contain only 0-9,a,b,c,d. Enter the number again: ";
		}
		else {
			input = false;
		}
	}
	std::cout << "The number in 10 score field: ";
	num_10 = convertin10(num_14, 0, 0);
	std::cout << num_10 << "\n";
	num_6 = convertin6(num_10, 0, 0);
	std::cout << "The number in 6 score field: ";
	std::cout << num_6;




}


