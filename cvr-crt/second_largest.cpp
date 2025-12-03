
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int solve(vector<int> arr, int n)
{

    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int secmax = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] < max && arr[i] > secmax)
        {
            secmax = arr[i];
        }
    }

    return secmax;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    // int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = solve(arr, n);

    cout << ans << endl;

    return 0;
}