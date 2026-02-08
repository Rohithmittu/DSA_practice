#include <iostream>
#include <vector>
#include <utility>
// #include <numeric>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int get_ans(int n, vector<int> &a, int p, int q, vector<pair<int, int>> &queries)
{
    int yesCount = 0;

    for (int qi = 0; qi < q; qi++)
    {
        int idx = queries[qi].first - 1; // convert to 0-based index
        int val = queries[qi].second;

        a[idx] = val;

        int cnt = 0;
        int g = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] % p == 0)
            {
                cnt++;
                if (g == 0)
                    g = a[i];
                else if (g >= a[i])
                {

                    g = gcd(g, a[i]);
                }
                else
                {
                    g = gcd(a[i], g);
                }
            }
        }

        if (cnt > 0 && g == p)
        {
            yesCount++;
        }
    }

    return yesCount;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int p;
    cin >> p;

    int q;
    cin >> q;

    int columns;
    cin >> columns; // always 2, but read as per input format

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    cout << get_ans(n, a, p, q, queries) << "\n";
    return 0;
}
