#include <iostream>
#include <string>


std::string convert(std::string StraightCode) // перевод числа в обратный код 
{

	std::string BackCode;

	if (StraightCode[0] == 0) // если число положительное то обратный код равен прямому коду
	{
		BackCode += StraightCode;
		BackCode.insert(0, 1, '0');
	}
	else if (StraightCode[0] == 1) // если число отрицательное то обратный код равен прямому коду с противоположными занчениями
	{
		StraightCode.insert(0, 1, '0');
		for (int i = 0; i < StraightCode.length(); i++) // получение обратного кода, путем смены значений всех элементов
		{
			if (StraightCode[i] == '1') StraightCode[i] = '0';
			else StraightCode[i] = '1';
		}
		BackCode.push_back('1');
		BackCode += StraightCode;
	}
	else BackCode.push_back('0');
	return BackCode;
}

void validation(std::string& num) {
	bool input = true;
	while (input) {// проверка на ввод
		getline(std::cin, num);

		if (num.find_first_not_of("01") <= num.size()) {
			std::cout << "The number should contain 0 and 1. Enter the number again: ";
		}
		else {
			input = false;
		}
	}
}

int main() {
	std::string num_1;
	std::string num_2;

	std::cout << "Enter the first number\n";

	validation(num_1);

	std::cout << "Enter the second number\n";

	validation(num_2);

	convert(num_1);
	convert(num_2);
	std::string sum;
	int count = 0;
	for (int i = num_1.length() - 1; i >= 0; i--) // нахождение суммы
	{
		if (count == 1)// счетчик на случай переполнения разряда
		{
			num_1[i]++;
			count = 0;
		}
		if (num_1[i] + num_2[i] - 96 > 1)// условие переполнения разряда
		{
			sum.insert(0, 1, '0');
			count++;
		}
		else if (num_1[i] + num_2[i] - 96 == 1) sum.insert(0, 1, '1');
		else sum.insert(0, 1, '0');
	}

	std::cout << "The sum in back code:  " << sum << "\n";
	if (sum[0] == '1') {
		for (int i = 0; i < sum.size(); i++) {
			if (sum[i] == '1') { sum[i] = '0'; }
			else { sum[i] = '1'; }
		}
	}

	std::cout << "The sum in length code:  " << sum;


}
