int minimumSwap(int arr[], int n, int k)
{
    // count of elements <= k
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++cnt;
    // count of unwanted elements in window of size cnt.
    int ucnt = 0;
    for (int i = 0; i < cnt; ++i)
        if (arr[i] > k)
            ++ucnt;
    int ans = ucnt;
    for (int i = 0, j = cnt; j < n; ++i, ++j)
    {
        if (arr[i] > k)
            --ucnt;
        if (arr[j] > k)
            ++ucnt;
        ans = min(ans, ucnt);
    }
    return ans;
}