#include <iostream>
using namespace std;

bool is_prime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

void prime_range(int input1, int input2) {
    if (input1 <= 0 || input2 <= 0 || input1 >= input2) {
        std::cout << "Provide valid input" << std::endl;
        return;
    }
    for (int num = input1; num <= input2; ++num) {
        if (is_prime(num))
            std::cout << num <<" ";
    }
}

int main() {
    int input1, input2;
    std::cin >> input1 >> input2;
    prime_range(input1, input2);
    return 0;
}
