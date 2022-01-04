#include <iostream>
#include <string>

int charToint(char x) {
	return x - '0';
}

int main() {
	std::string num1;
	std::cout << "Enter the first number:  ";
	getline(std::cin, num1);
	std::cout << "Enter the second number:  ";
	std::string num2;
	getline(std::cin, num2);

	if (num1.length() > num2.length())
	{
		while (num1.length() != num2.length()) num2.insert(2, 1, '0'); // если длина первого числа больше второго, дополнить второе нулями
	}
	else if (num1.length() < num2.length())
	{
		while (num1.length() != num2.length()) num1.insert(2, 1, '0'); // если длина второго числа больше первого, дополнить первое нулями
	}

	std::string sum;
	int cur = 0; // для перегрузки разряда
	for (int i = num1.size() - 1; i >= 0; i--) {
		int temp = charToint(num1[i]) + charToint(num2[i]) + cur;
		cur = 0;
		if (temp <= 13) {// если в число в разряде меньше 13, то мы его записываем, если больше 13, то перегружаем разряд
			if (temp > 9) {

				if (temp == 10) {
					sum.insert(0, 1, 'a');
				}
				if (temp == 11) {
					sum.insert(0, 1, 'b');
				}
				if (temp == 12) {
					sum.insert(0, 1, 'c');
				}
				if (temp == 13) {
					sum.insert(0, 1, 'd');
				}
			}
			else {
				sum.insert(0, 1, temp + '0');
			}
		}

		if (temp > 13) {// случай перегрузки разряда
			if (i == 0) {
				sum.insert(0, 1, temp / 14 + '0');
				sum.insert(0, 1, temp % 14 + '0');
			}
			else {
				if (temp % 14 > 9) {

					if (temp % 14 == 10) {
						sum.insert(0, 1, 'a');
					}
					if (temp % 14 == 11) {
						sum.insert(0, 1, 'b');
					}
					if (temp % 14 == 12) {
						sum.insert(0, 1, 'c');
					}
					if (temp % 14 == 13) {
						sum.insert(0, 1, 'd');
					}
				}
				else {
					sum.insert(0, 1, temp % 14 + '0');
				}
				cur = temp / 14;
			}
		}
	}

	std::cout << "Sum in 14 score field: " << sum;




}
