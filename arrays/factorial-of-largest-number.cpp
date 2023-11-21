#include <bits/stdc++.h>
string multiply(string& a, int b) {
    string result;
    int carry = 0;

    for (int i = a.size() - 1; i >= 0 || carry > 0; --i) {
        int digit = (i >= 0) ? (a[i] - '0') : 0;
        int product = digit * b + carry;
        result = char(product % 10 + '0') + result;
        carry = product / 10;
    }

    return result;
} 
string calculateFactorial(int n)
{
    string result = "1";

    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
    }

    return result;
}