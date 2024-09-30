#include <string>
#include <iostream>

using namespace std;

string convert(int n) {
    string roman;
    string let[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; i++) {  
        while (n >= num[i]) {
            roman += let[i];
            n -= num[i];
        }
    }

    return roman;
}

int main() {
    int number;
    cout << "Give me a number to convert: ";
    cin >> number;
    string change = convert(number);
    cout << "The Roman Numeral of " << number << " is " << change;
}