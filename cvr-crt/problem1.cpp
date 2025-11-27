// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    vector<int> nums(x);

    for(int i = 0; i < x; i++){
        cin >> nums[i];
    }

    vector<vector<int>> lab(y, vector<int>(3, 0));

    for(int i = 0; i < y; i++){
        cin >> lab[i][0] >> lab[i][1];
    }

    // Count how many nums fall in each interval
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(nums[i] > lab[j][0] && nums[i] < lab[j][1]){
                lab[j][2]++;
            }
        }
    }

    // Print the results
    for(int j = 0; j < y; j++){
        cout << lab[j][2]<< endl;
    }
    cout << endl;

    return 0;
}



// input
// 10 2 345 604 321 433 704 470 808 718 517 811 300 350 400 700
