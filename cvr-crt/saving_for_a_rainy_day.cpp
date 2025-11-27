#include <iostream>
#include <cmath>
using namespace std;

int main(){

    double amount,months,interest;

    cin >> amount;
    cin >> months;
    cin >> interest;


    double rate_per_month = (interest/100) / 12;

    // formula = emi_amount * ((1-(1+r))^-n)/r

    double money_to_put = amount * (1 - pow(1+rate_per_month,-months)) / rate_per_month;

    cout << money_to_put << endl;


    return 0;
}