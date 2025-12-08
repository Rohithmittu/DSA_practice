#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        int pos = tolower(c) - 'a' + 1;  // Alphabet position

        // Append character + position
        result += c + to_string(pos);

        // If next character is the same, add "*"
        if (i < s.length() - 1 && s[i] == s[i + 1]) {
            result += "*";
        }
    }

    cout << result;
    return 0;
}
