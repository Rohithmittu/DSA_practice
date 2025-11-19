class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int n = nums.size();

        // if (n == 1) return nums[0];
        // if (nums[0] != nums[1]) return nums[0];
        // if (nums[n-1] != nums[n-2]) return nums[n-1];

        // for (int i = 1; i < n - 1; i++) {
        //     if (nums[i] != nums[i-1] && nums[i] != nums[i+1]) {
        //         return nums[i];
        //     }
        // }

        // return -1;

        // int x = 0;
        // for (int num : nums) {
        //     x ^= num;
        // }
        // return x;



        int n = nums.size();

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        int s = 0, e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if (mid % 2 == 0) {

                if (nums[mid - 1] == nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }

            } else {

                if (nums[mid - 1] == nums[mid]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }

        return -1;
    }
};
