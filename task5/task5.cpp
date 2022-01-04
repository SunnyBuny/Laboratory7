#include <iostream>
#include <vector>

int i = 0;
// перевод будем осуществлять чисел меньших либо равных 3999, потому что перевод больших чисел будет не совсем корректным

// перевод тысяч в римскую систему
void thousand(int n, char* rim) {
	while (n != 0) {
		rim[i] = 'M';
		n--;
		i++;
	}
}

// перевод сотен в римскую систему
void hundred(int n, char* rim) {
	if (n == 9) {
		rim[i] = 'C';
		i++;
		rim[i] = 'M';
		i++;
	}

	if (n == 5) {
		rim[i] = 'D';
		i++;
	}

	if (n == 4) {
		rim[i] = 'C';
		i++;
		rim[i] = 'D';
		i++;
	}
	if (n > 0 && n < 4) {
		while (n != 0) {
			rim[i] = 'C';
			i++;
			n--;
		}

	}
	if (n > 5 && n < 9) {
		rim[i] = 'D';
		i++;
		while (n != 5) {
			rim[i] = 'C';
			i++;
			n--;
		}

	}
}

// перевод десятков в римскую систему
void tens(int n, char* rim) {
	if (n == 5) {
		rim[i] = 'L';
		i++;
	}
	if (n == 9) {
		rim[i] = 'X';
		i++;
		rim[i] = 'C';
		i++;
	}
	if (n == 4) {
		rim[i] = 'X';
		i++;
		rim[i] = 'L';
		i++;
	}

	if (n > 0 && n < 4) {
		while (n != 0) {
			rim[i] = 'X';
			i++;
			n--;
		}

	}
	if (n > 5 && n < 9) {
		rim[i] = 'L';
		i++;
		while (n != 5) {
			rim[i] = 'X';
			i++;
			n--;
		}

	}

}
// перевод единиц в римскую систему
void numbers(int n, char* rim) {
	if (n == 5) {
		rim[i] = 'V';
		i++;
	}
	if (n == 9) {
		rim[i] = 'I';
		i++;
		rim[i] = 'X';
		i++;
	}
	if (n == 4) {
		rim[i] = 'I';
		i++;
		rim[i] = 'V';
		i++;
	}

	if (n > 0 && n < 4) {
		while (n != 0) {
			rim[i] = 'I';
			i++;
			n--;
		}

	}
	if (n > 5 && n < 9) {
		rim[i] = 'V';
		i++;
		while (n != 5) {
			rim[i] = 'I';
			i++;
			n--;
		}

	}
}

int main() {
	int n;
	std::cout << "Enter the number in 10 field" << "\n";
	while (!(std::cin >> n) || n < 0) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}

	char rim[16];
	int pos[4];// для записи цифр стоящих в разрядах десятичного числа
	int k = 0;
	while (n != 0) {
		pos[k] = n % 10;
		n /= 10;
		k++;
	}
	if (k == 4) {
		thousand(pos[3], rim);
		hundred(pos[2], rim);
		tens(pos[1], rim);
		numbers(pos[0], rim);
	}
	if (k == 3) {
		hundred(pos[2], rim);
		tens(pos[1], rim);
		numbers(pos[0], rim);
	}
	if (k == 2) {
		tens(pos[1], rim);
		numbers(pos[0], rim);
	}
	if (k == 1) {
		numbers(pos[0], rim);
	}
	for (int j = 0; j < i; j++) {
		std::cout << rim[j];
	}




}
