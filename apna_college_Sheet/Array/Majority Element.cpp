// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int n = nums.size();
//         // for(int i = 0;i<n;i++){

//         //     int freq = 0;

//         //     for(int j = 0;j<n;j++){
//         //         if(nums[j] == nums[i]){
//         //             freq++;

//         //         }

//         //     }
//         //     if(freq > n/2){
//         //         return nums[i];
//         //     }

//         // }

//         // return -1;

//         // for(int val: nums){
//         //     int freq = 0;
//         //     for(int el: nums){
//         //         if(el == val){
//         //             freq++;

//         //         }

//         //     }
//         //     if(freq > n/2){
//         //         return val;
//         //     }
//         // }

//         // return -1;

//         // O(n^2)

//         // if(n == 1){
//         //     return nums[0];
//         // }

//         // sort(nums.begin(), nums.end());

//         // int freq = 1, ans = nums[0];

//         // for (int i = 1; i < n; i++) {

//         //     if (nums[i] == nums[i - 1]) {
//         //         freq++;
//         //     } else {
//         //         freq = 1;
//         //         ans = nums[i];
//         //     }

//         //     if (freq > n / 2) {
//         //         return ans;
//         //     }
//         // }

//         // return -1;

//         // O(nlogn)

//         int ans = 0, freq = 0;

//         for (int i = 0; i < n; i++) {

//             if (freq == 0) {
//                 ans = nums[i];
//             }

//             if (ans == nums[i]) {
//                 freq++;

//             } else {
//                 freq--;
//             }
//         }

//         return ans;

//         // O(N)
//     }
// };


#include <bits/stdc++.h>
using namespace std;

// Boyer–Moore Majority Vote Algorithm
int majorityElement(vector<int>& nums) {
    int ans = 0, freq = 0;

    for (int num : nums) {
        if (freq == 0) {
            ans = num;
        }
        if (ans == num) {
            freq++;
        } else {
            freq--;
        }
    }

    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    cin >> n;   // size of array
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << majorityElement(nums) << "\n";

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0, freq = 0;

//         // Boyer–Moore Majority Vote Algorithm
//         for (int i = 0; i < n; i++) {
//             if (freq == 0) {
//                 ans = nums[i];
//             }
//             if (ans == nums[i]) {
//                 freq++;
//             } else {
//                 freq--;
//             }
//         }

//         return ans;
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t; 
//     cin >> t;  // number of test cases

//     while (t--) {
//         int n;
//         cin >> n;  // size of array
//         vector<int> nums(n);

//         for (int i = 0; i < n; i++) {
//             cin >> nums[i];
//         }

//         Solution sol;
//         cout << sol.majorityElement(nums) << "\n";
//     }

//     return 0;
// }
