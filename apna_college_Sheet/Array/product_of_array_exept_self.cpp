class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // int n = nums.size();
        // vector<int> ans(n);

        // for (int i = 0; i < n; i++) {
        //     int product = 1;
        //     for (int j = 0; j < n; j++) {
        //         if (j == i) continue;
        //         product *= nums[j];
        //     }
        //     ans[i] = product;
        // }

        // return ans;

        // TC--O(n^2);
        // SC-- O(n);

        // int n = nums.size();
        // int product = 1;
        // int zeroCount = 0;

        // for (int num : nums) {
        //     if (num == 0) zeroCount++;
        //     else product *= num;
        // }

        // vector<int> ans(n, 0);

        // for (int i = 0; i < n; i++) {
        //     if (zeroCount > 1) ans[i] = 0;           // more than 1 zero →
        //     all are zero else if (zeroCount == 1 && nums[i] != 0) ans[i] = 0;
        //     else if (zeroCount == 1 && nums[i] == 0) ans[i] = product; //
        //     only the zero position gets product else ans[i] = product /
        //     nums[i];         // normal division case
        // }

        // return ans;

        // TC-- O(n);
        // SC-- O(n);

        // int n = nums.size();
        // vector<int> prefix(n,1);
        // vector<int> suffix(n,1);
        // vector<int> ans(n);

        // // 1 2 3 4
        // // 1 1 2 6
        // // 24 12 4 1

        // for(int i = 1;i<n;i++){
        //     prefix[i] = prefix[i-1] * nums[i-1];
        // }

        // for(int i = n-2;i>=0;i--){
        //     suffix[i] = suffix[i+1] * nums[i+1];
        // }

        // for(int i = 0;i<n;i++){
        //     ans[i] = prefix[i] * suffix[i];
        // }

        // return ans;

        // TC-- O(n);
        // SC-- O(n);

        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;

        for (int i = n - 2; i >= 0; i--) {
            suffix = nums[i + 1] * suffix;

            ans[i] = ans[i] * suffix;
        }

        return ans;

        // TC-- O(n);
        // SC-- O(1);
    }
};
