class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        // int ans = 0;

        // for (int i = 0; i < height.size(); i++) {
        //     for (int j = i + 1; j < height.size(); j++) {
        //         int left = height[i];
        //         int right = height[j];

        //         int width = j - i;
        //         int length = min(left, right);

        //         int area = length * width;

        //         ans = max(area, ans);
        //     }
        // }

        // return ans;

        // O(n^2)

        int ans = 0;

        int left = 0, right = height.size() - 1;

        while (left < right)
        {
            int width = right - left;
            int length = min(height[left], height[right]);

            int area = width * length;

            ans = max(area, ans);

            height[left] < height[right] ? left++ : right--;
        }

        return ans;

        // O(n)
    }
};