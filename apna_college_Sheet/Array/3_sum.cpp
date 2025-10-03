class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // int n = nums.size();
        // vector<vector<int>> ans;

        // set<vector<int>> s;

        // for(int i = 0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         for(int k = j+1;k<n;k++){
        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 vector<int> dump = {nums[i],nums[j],nums[k]};

        //                 sort(dump.begin(),dump.end());
        //                 if(s.find(dump) == s.end()){
        //                     s.insert(dump);
        //                     ans.push_back(dump);
        //                 }
        //             }
        //         }
        //     }
        // }

        // return ans;

        // O(n^3 * lon n);

        // int n = nums.size();

        // set<vector<int>> triplets;

        // for (int i = 0; i < n; i++) {

        //     int tar = -nums[i];

        //     set<int> s;

        //     for (int j = i + 1; j < n; j++) {

        //         int third = tar - nums[j];

        //         if (s.find(third) != s.end()) {

        //             vector<int> dump = {nums[i], nums[j], third};

        //             sort(dump.begin(), dump.end());

        //             triplets.insert(dump);
        //         }

        //         s.insert(nums[j]);
        //     }
        // }

        // vector<vector<int>> ans(triplets.begin(), triplets.end());

        // return ans;

        // O(n^2 * lon n)

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {

                    j++;

                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        return ans;

        // O(nlogn + n^2);
    }
};