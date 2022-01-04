#include <iostream>
using namespace std;

int sub(int x, int y) { // побитовое вычитание
    while (y) {
        int z = (~x) & y;
        x = x ^ y;
        y = z << 1;
    }
    return x;
}

int divide(int x, int y) { // побитовое деление
    int res = 0;
    while (x >= y) {
        int i = 0, t = y;
        while (x >= (t << 1)) {
            i++;
            t <<= 1;
        }
        res |= 1 << i;
        x = sub(x, t);
    }
    return res;
}

int multiply(int x, int y) { //побитовое умножение
    int result = 0;
    while (y)
    {
        if (y & 01)
        {
            result += x;
        }
        x <<= 1;
        y >>= 1;
    }
    return result;
}

bool mod(int x, int y) { //проверка на делимость
    if (sub(x, multiply(divide(x, y), y)) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cout << "Enter tne integer number\n";
    while (!(cin >> n) || n < 0) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Enter tne integer number again\n";
    }

    if (mod(n, 5)) {
        cout << "Tne number is devided on 5\n";
    }
    else {
        cout << "Tne number is not  devided on 5\n";
    }

    if (mod(n, 53)) {
        cout << "Tne number is devided on 53\n";
    }
    else {
        cout << "Tne number is not  devided on 53\n";
    }

    if (mod(n, 109)) {
        cout << "Tne number is devided on 109\n";
    }
    else {
        cout << "Tne number is not  devided on 109\n";
    }

}
