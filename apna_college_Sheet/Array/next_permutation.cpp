class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int pivot = -1, n = nums.size();

        // step 1: find the disturbing order form the back of the array

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }

        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // step 2: swap the disturbing element with the elemnt bigger from the back
        for (int i = n - 1; i > pivot; i--)
        {

            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // step 3: after  pivot element swap all the elemnet afdter pivot to get next permutaion;
        int i = pivot + 1, j = n - 1;
        while (i <= j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};