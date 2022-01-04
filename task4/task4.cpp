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
		while (num1.length() != num2.length()) num2.insert(2, 1, '0'); // ���� ����� ������� ����� ������ �������, ��������� ������ ������
	}
	else if (num1.length() < num2.length())
	{
		while (num1.length() != num2.length()) num1.insert(2, 1, '0'); // ���� ����� ������� ����� ������ �������, ��������� ������ ������
	}

	std::string sum;
	int cur = 0; // ��� ���������� �������
	for (int i = num1.size() - 1; i >= 0; i--) {
		int temp = charToint(num1[i]) + charToint(num2[i]) + cur;
		cur = 0;
		if (temp <= 13) {// ���� � ����� � ������� ������ 13, �� �� ��� ����������, ���� ������ 13, �� ����������� ������
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

		if (temp > 13) {// ������ ���������� �������
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
