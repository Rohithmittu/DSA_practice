
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    int cnt = 1;

    int l = 0, r = n - 1, down = n - 1, top = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         v[i][j] = cnt;
    //         cnt++;
    //     }
    // }

    while (l <= r && top <= down)
    {

        for (int i = l; i <= r; i++)
        {
            v[top][i] = cnt;
            cnt++;
        }
        top++;

        for (int i = top; i <= down; i++)
        {
            v[i][r] = cnt;
            cnt++;
        }
        r--;

        for (int i = r; i >= l; i--)
        {

            v[down][i] = cnt;
            cnt++;
        }

        down--;

        for (int i = down; i >= top; i--)
        {
            v[i][l] = cnt;
            cnt++;
        }

        l++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j];
            if(j != n-1){
                cout << "\t" << endl;
            }
        }
        cout << endl;
    }

    vector<pair<int, int>> ans;

    ans.push_back({0, 0});

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = v[i][j];

            if (temp % 11 == 0)
            {
                ans.push_back({i, j});
            }
        }
    }

    int count = ans.size();

    cout << count << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "(" << ans[i].first << "," << ans[i].second << ")" << endl;
        // cout << ans[i].first << ans[i].second << endl;
    }

    return 0;
}
