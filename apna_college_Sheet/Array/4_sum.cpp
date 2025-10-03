class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n;) {

                int l = j + 1, k = n - 1;

                while (l < k) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + 
                                        (long long)nums[l] + (long long)nums[k];

                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        k--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[k]});
                        l++;
                        k--;

                        while (l < n && nums[l] == nums[l - 1]) {
                            l++;
                        }
                    }
                }

                j++;

                while (j < n && nums[j] == nums[j - 1]) {

                    j++;
                }
            }
        }

        return ans;

        // O(nlogn + n^3);
    }
};