class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right, int& cnt) {

        // step 1
        int l = left;
        int r = mid + 1;

        while (l <= mid && r <= right) {
            if (nums[l] > 2LL * nums[r]) {
                cnt += (mid - l + 1);
                r++;
            } else {
                l++;
            }
        }

        // step 2
        vector<int> temp;

        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[left + i] = temp[i];
        }
    }

    void mergesort(vector<int>& nums, int left, int right, int& cnt) {

        if (left < right) {
            int mid = left + (right - left) / 2;

            mergesort(nums, left, mid, cnt);
            mergesort(nums, mid + 1, right, cnt);

            merge(nums, left, mid, right, cnt);
        }
    }

    int reversePairs(vector<int>& nums) {

        // int n = nums.size();

        // int cnt = 0;

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {

        //         if (nums[i] > 2LL * nums[j]) {
        //             cnt++;
        //         }
        //     }
        // }

        // return cnt;

        int n = nums.size();

        int cnt = 0;

        mergesort(nums, 0, n - 1, cnt);

        return cnt;
    }
};