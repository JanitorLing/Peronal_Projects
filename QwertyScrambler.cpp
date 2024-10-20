#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to create a mapping based on the QWERTY keyboard layout
// The mapping will either be for encryption or decryption
unordered_map<char, char> createQwertyMap(bool isEncryption) {
    // QWERTY keyboard mappings
    string qwerty = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    string shifted = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";

    unordered_map<char, char> mapping;
    if (isEncryption) {
        for (size_t i = 0; i < qwerty.length(); ++i) {
            mapping[qwerty[i]] = qwerty[(i + 1) % qwerty.length()];
        }
        for (size_t i = 0; i < shifted.length(); ++i) {
            mapping[shifted[i]] = shifted[(i + 1) % shifted.length()];
        }
    } else {
        for (size_t i = 0; i < qwerty.length(); ++i) {
            mapping[qwerty[(i + 1) % qwerty.length()]] = qwerty[i];
        }
        for (size_t i = 0; i < shifted.length(); ++i) {
            mapping[shifted[(i + 1) % shifted.length()]] = shifted[i];
        }
    }
    return mapping;
}

// Function to process the text by encrypting or decrypting it based on the mapping
string processText(const string& text, bool isEncryption) {
    auto mapping = createQwertyMap(isEncryption);
    string result;

    // Iterate through each character in the text
    for (char c : text) {
        // If the character is in the mapping, replace it with the mapped character
        if (mapping.find(c) != mapping.end()) {
            result += mapping[c];
        } else {
            result += c; // Keep non-mapped characters unchanged
        }
    }
    return result;
}

int main() {
    string choice;
    // Loop until the user provides a valid choice (encrypt or decrypt)
    while (true) {
        cout << "Do you want to encrypt or decrypt? (enter 'e' or 'd'): ";
        cin >> choice;

        if (choice == "e" || choice == "d") {
            break;
        } else {
            cout << "Invalid choice. Please enter 'e' or 'd'.\n";
        }
    }

    // Determine if the user wants to encrypt or decrypt
    bool isEncryption = (choice == "e");

    // Get the text input from the user
    cout << "Enter the text: ";
    string text;
    cin.ignore(); // Ignore the leftover newline character
    getline(cin, text);

    // Process the text and display the result
    string result = processText(text, isEncryption);
    cout << "Result: " << result << endl;

    return 0;
}
