#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isexists(vector<vector<char>> grid, string word, int i, int j, int n, int m, int s, int x[], int y[])
    {

        for (int direc = 0; direc < 8; direc++)
        {
            int i1 = i, j1 = j, k = 0;
            int x1 = x[direc], y1 = y[direc];

            while (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && k < s)
            {
                if (word[k] == grid[i1][j1])
                {
                    i1 = i1 + x1;
                    j1 = j1 + y1;
                    k++;
                }
                else
                {
                    break;
                }
            }

            if (k == s)
            {
                return true;
            }
        }

        return false;
    }

    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {

        vector<vector<int>> ans;

        vector<int> p(2);

        int x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int y[8] = {1, 1, 1, 0, -1, -1, -1, 0};

        int n = grid.size();
        int m = grid[0].size();
        int s = word.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isexists(grid, word, i, j, n, m, s, x, y))
                {
                    p[0] = i;
                    p[1] = j;
                    ans.push_back(p);
                }
            }
        }

        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
        else
        {
            for (auto i : ans)
            {
                for (auto j : i)
                    cout << j << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}