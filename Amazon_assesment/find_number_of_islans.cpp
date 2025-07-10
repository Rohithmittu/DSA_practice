// #include<bits/stdc++.h>

// void bfs(int row ,int col , vector<vector<int>> &vis , int **arr ,int n , int m){
//    vis[row][col] = 1;
//    queue<pair<int,int>> q;
   
//    q.push({row,col});
//    int delrow[4] = {-1,0,1,0};
//    int delcol[4] = {0,1,0,-1};

//    while(!q.empty()){
//       int row = q.front().first;
//       int col = q.front().second;
//       q.pop();

//       for(int i = 0 ; i<4 ; i++){
//          for(int j = 0 ; j<4 ; j++){
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[j];

//             if(nrow >= 0 && ncol >= 0 && nrow<n && ncol<m && arr[nrow][ncol] == 1 && vis[nrow][ncol] != 1){
//                vis[nrow][ncol] = 1;
//                q.push({nrow,ncol});
//             }
//          }
//       }
//    }
// }

// int getTotalIslands(int** arr, int n, int m)
// {
//    // Write your code here.
//    vector<vector<int>> vis(n,vector<int>(m,0));
//    int islands = 0;

//    for(int i  = 0 ; i<n ; i++){
//       for(int j = 0 ; j<m ; j++){
//          if(arr[i][j] == 1 && vis[i][j] != 1){
//             bfs(i,j,vis,arr,n,m);
//             islands++;
//          }
//       }
//    }

//    return islands;
// }

// ******************************************************************************



/*
    Time Complexity: O(N * M)
    Space Complexity: O(N * M)

    Where N and M are the number of rows and columns of the 2D array, respectively.
*/

#include <vector>

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

/*
    dx[] and dy[] are the arrays that define each of the eight directions.

    dx[0], dy[0] : West
    dx[1], dy[1] : North-West
    dx[2], dy[2] : North
    dx[3], dy[3] : North-East
    dx[4], dy[4] : East
    dx[5], dy[5] : South-East
    dx[6], dy[6] : South
    dx[7], dy[7] : South-West

*/

vector<vector<bool>> vis;

void getTotalIslandsHelper(int** mat, int n, int m, int x, int y)
{
    // Check if this cell is valid.
    if(!(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !vis[x][y]))
    {
        return;
    }

    vis[x][y] = true;

    for(int i=0; i<8; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        getTotalIslandsHelper(mat, n, m, nextX, nextY);
    }
}

int getTotalIslands(int** mat, int n, int m)
{
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    int islands = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] == 1 && !vis[i][j])
            {
                // We have found an undiscovered island.
                islands++;
                getTotalIslandsHelper(mat, n, m, i, j);
            }
        }
    }

    return islands;
}