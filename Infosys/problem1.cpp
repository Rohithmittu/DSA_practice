// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

static const long long MOD = 1000000007;

/*
 Compute square-free part of x:
 product of primes whose exponent in x is odd
*/
long long squareFree(long long x)
{
    long long res = 1;
    for (long long p = 2; p * p <= x; ++p)
    {
        if (x % p == 0)
        {
            int cnt = 0;
            while (x % p == 0)
            {
                x /= p;
                cnt++;
            }
            if (cnt % 2 == 1)
                res *= p;
        }
    }
    if (x > 1)
        res *= x;
    return res;
}

vector<vector<int>> tree;
vector<long long> sf; // square-free value of each node
long long answer = 0;

/*
 DFS returns a pointer to a map:
   square_free_value -> count in subtree
*/
unordered_map<long long, long long> *dfs(int u)
{
    auto *mp = new unordered_map<long long, long long>();

    // process children
    for (int v : tree[u])
    {
        auto *childMap = dfs(v);

        // small-to-large merge
        if (childMap->size() > mp->size())
            swap(mp, childMap);

        for (auto &kv : *childMap)
        {
            long long key = kv.first;
            long long cnt = kv.second;

            if (mp->count(key))
            {
                answer = (answer + mp->at(key) * cnt) % MOD;
            }
            (*mp)[key] += cnt;
        }
        delete childMap;
    }

    // count current node
    answer = (answer + (*mp)[sf[u]]) % MOD;
    (*mp)[sf[u]]++;

    return mp;
}

long long get_ans(int n,vector<int> &par,vector<long long> &a){
    tree.assign(n, {});
    sf.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        sf[i] = squareFree(a[i]);
    }

    // build tree (root = 0)
    for (int i = 1; i < n; i++)
    {
        tree[par[i]].push_back(i);
    }

    answer = 0;
    auto *rootMap = dfs(0);
    delete rootMap;

    return answer % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> par(n);
    for (int i = 0; i < n; i++)
    {
        cin >> par[i];
    }

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << get_ans(n, par, a) << "\n";
    return 0;
}
