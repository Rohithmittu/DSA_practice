class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // int n = nums.size();

        // vector<int> ans;

        // for (int i = 0; i <= n - k; i++) {
        //     int maxi = INT_MIN;
        //     for (int j = i; j < i + k; j++) {

        //         maxi = max(maxi, nums[j]);
        //     }

        //     ans.push_back(maxi);
        // }

        // return ans;

        int n = nums.size();
        deque<int> d;
        vector<int> ans;

        //  first k index
        for (int i = 0; i < k; i++)
        {
            while (!d.empty() && nums[d.back()] <= nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
        }

        for (int i = k; i < n; i++)
        {

            ans.push_back(nums[d.front()]);

            // remove less than window
            while (!d.empty() && d.front() <= i - k)
            {
                d.pop_front();
            }

            // remove small elemnets
            while (!d.empty() && nums[d.back()] <= nums[i])
            {
                d.pop_back();
            }

            d.push_back(i);
        }

        ans.push_back(nums[d.front()]);

        return ans;
    }
};