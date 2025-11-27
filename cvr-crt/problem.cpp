// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums)
{

    int n = nums.size();

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        while (nums[i] != 0)
        {
            int r = nums[i] % 6;
            sum = sum + r;
            nums[i] = nums[i] / 6;
        }

        temp[i] = sum;
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (temp[i] > temp[j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = solve(arr);
    
    cout << ans << endl;


}
