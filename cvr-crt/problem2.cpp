// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int cnt = 0;

void dfs(int n, int start, int sum, int taken)
{
    if (sum == n)
    {
        if (taken >= 2) // exclude "10" alone
            cnt++;
        return;
    }
    if (sum > n)
        return;

    for (int i = start; i <= n; i++)
    {
        dfs(n, i + 1, sum + i, taken + 1);
    }
}

int main()
{
    int n;
    cin >> n;

    dfs(n, 1, 0, 0);

    cout << cnt << endl;
    return 0;
}
