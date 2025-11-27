#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Rotate function
string rotateString(string s, char dir, int k) {
    int n = s.length();
    k = k % n;

    if (dir == 'L')
        return s.substr(k) + s.substr(0, k);
    else  // 'R'
        return s.substr(n - k) + s.substr(0, n - k);
}

// Anagram substring check using sliding window
bool isAnagramSubstring(string s, string target) {
    int n = s.length();
    int k = target.length();

    if (k > n) return false;

    vector<int> tf(256, 0), wf(256, 0);

    for (char c : target)
        tf[c]++;

    for (int i = 0; i < k; i++)
        wf[s[i]]++;

    if (tf == wf)
        return true;

    for (int i = k; i < n; i++) {
        wf[s[i]]++;        // add new char
        wf[s[i - k]]--;    // remove old char

        if (tf == wf)
            return true;
    }

    return false;
}

int main() {
    string s;
    int r;


    cin >> s >> r;

    string current = s;
    string firstCharString = "";

    for (int i = 0; i < r; i++) {
        char dir;
        int k;
        cin >> dir >> k;

        current = rotateString(current, dir, k);
        firstCharString += current[0];
    }

    if (isAnagramSubstring(s, firstCharString))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
