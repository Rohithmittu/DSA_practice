// class Solution
// {
// public:
//     void solve(vector<vector<int>> &maze, int row, int col, vector<string> &ans, string temp, vector<vector<bool>> &vis)
//     {

//         int n = maze.size();

//         if (row >= n || col >= n || row < 0 || col < 0 || maze[row][col] == 0 || vis[row][col] == true)
//         {
//             return;
//         }

//         if (row == n - 1 && col == n - 1)
//         {
//             ans.push_back(temp);
//             return;
//         }

//         vis[row][col] = true;

//         solve(maze, row + 1, col, ans, temp + "D", vis);
//         solve(maze, row, col - 1, ans, temp + "L", vis);
//         solve(maze, row, col + 1, ans, temp + "R", vis);
//         solve(maze, row - 1, col, ans, temp + "U", vis);

//         vis[row][col] = false;
//     }

//     vector<string> ratInMaze(vector<vector<int>> &maze)
//     {
//         // code here
//         int n = maze.size();
//         vector<string> ans;
//         string temp = "";
//         vector<vector<bool>> vis(n, vector<bool>(n, false));

//         solve(maze, 0, 0, ans, temp, vis);

//         return ans;
//     }
// };

class Solution
{
public:
    void solve(vector<vector<int>> &maze, int row, int col, vector<string> &ans, string temp)
    {

        int n = maze.size();

        if (row >= n || col >= n || row < 0 || col < 0 || maze[row][col] == 0 || maze[row][col] == -1)
        {
            return;
        }

        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(temp);
            return;
        }

        maze[row][col] = -1;

        solve(maze, row + 1, col, ans, temp + "D");
        solve(maze, row, col - 1, ans, temp + "L");
        solve(maze, row, col + 1, ans, temp + "R");
        solve(maze, row - 1, col, ans, temp + "U");

        maze[row][col] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here
        int n = maze.size();
        vector<string> ans;
        string temp = "";

        solve(maze, 0, 0, ans, temp);

        return ans;
    }
};