#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int maxindex = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxindex = max(nums[i], maxindex + nums[i]);
            res = max(res, maxindex);

            if(maxindex < 0){
                maxindex = 0;
            }


        }
        return res;
    }
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int ans = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum = " << ans << "\n";


    return 0;
}
