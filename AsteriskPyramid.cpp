#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Give me a number: ";
    cin >> n;

    for (int i = 1; i <= n; i += 2) {
        for (int k = 0; k < (n-i) / 2; k++) {
            cout << " ";
        }
        for (int j = 0; j <i; j++) {
            cout << "*";
        }
    cout << endl;
    }
    
    return 0;
}
