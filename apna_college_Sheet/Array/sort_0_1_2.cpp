class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());

        int count_zero = 0, count_one = 0, count_two = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) {
                count_zero++;
            } else if (nums[i] == 1) {
                count_one++;
            } else {
                count_two++;
            }
        }

        int idx = 0;
        for (int i = 0; i < count_zero; i++) {
            nums[idx] = 0;
            idx++;
        }
        for (int i = 0; i < count_one; i++) {
            nums[idx] = 1;
            idx++;
        }
        for (int i = 0; i < count_two; i++) {
            nums[idx] = 2;
            idx++;
        }
    }
};