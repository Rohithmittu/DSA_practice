#include <bits/stdc++.h>
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        // int i = 0, j = 0, k = 0;
        // vector<int> ans;

        // while (i < m && j < n) {
        //     if (nums1[i] < nums2[j]) {

        //         ans.push_back(nums1[i]);
        //         i++;

        //     } else {

        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        //     k++;
        // }

        // while (i < m) {
        //     ans.push_back(nums1[i]);
        //     i++;
        // }

        // while (j < n) {
        //     ans.push_back(nums2[j]);
        //     j++;
        // }

        // nums1 = ans;

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
        }
    }
};