#include<iostream>
#include <string>

int convert(std::string num) {
	int num_10 = 0;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == 'a') { num_10 += 10 * pow(14, num.size() - i - 1); }
		if (num[i] == 'b') { num_10 += 11 * pow(14, num.size() - i - 1); }
		if (num[i] == 'c') { num_10 += 12 * pow(14, num.size() - i - 1); }
		if (num[i] == 'd') { num_10 += 13 * pow(14, num.size() - i - 1); }
		if (num[i] >= 48 && num[i] <= 57) { num_10 += (num[i] - 48) * pow(14, num.size() - i - 1); }
	}
	return num_10;
}
// нужно перевести числа из 14ти ричной системы счисления в 6ти ричную
int main() {
	std::string num_14;
	int num_10;
	std::cout << "Enter tne number in 14 score field" << "\n";
	bool input = true;

	while (input) {// проверка на ввод
		getline(std::cin, num_14);
		if (num_14.size() == 0 || num_14.size() > 10) {
			std::cout << "The minimum number of digits is 1 and maximum is 10. Enter the number again: ";
		}
		else if (num_14.find_first_not_of("0123456789abcd") <= num_14.size()) {
			std::cout << "The number should contain only 0-9,a,b,c,d. Enter the number again: ";
		}
		else {
			input = false;
		}
	}
	num_10 = convert(num_14);
	int num_6[100];
	int i = 0;
	while (num_10 != 0) {
		num_6[i] = num_10 % 6;
		num_10 /= 6;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		std::cout << num_6[j];
	}

}
