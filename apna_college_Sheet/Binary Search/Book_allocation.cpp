class Solution
{
public:
    bool isvalid(vector<int> &arr, int n, int k, int maxallowed)
    {
        int stud = 1, pages = 0;

        for (int i = 0; i < n; i++)
        {

            if (arr[i] > maxallowed)
            {
                return false;
            }

            if (arr[i] + pages <= maxallowed)
            {
                pages += arr[i];
            }
            else
            {
                stud++;
                pages = arr[i];
            }
        }

        if (stud <= k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int findPages(vector<int> &arr, int k)
    {

        int n = arr.size();

        if (k > n)
        {
            return -1;
        }

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        int ans = -1;
        int s = 0, e = sum;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (isvalid(arr, n, k, mid))
            {

                ans = mid;

                e = mid - 1;
            }
            else
            {

                s = mid + 1;
            }
        }

        return ans;
    }
};