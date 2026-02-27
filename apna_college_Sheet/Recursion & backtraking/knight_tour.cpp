class Solution {
public:
    bool solve(vector<vector<int>>& grid,int row,int col,int expected,int n){

        if(row >= n || col >= n || row < 0 || col < 0 || grid[row][col] != expected){
            return false;
        }

        if(expected == n*n-1){
            return true;
        }


        bool ans1 = solve(grid,row-2,col+1,expected + 1,n);
        bool ans2 = solve(grid,row-1,col+2,expected + 1,n);
        bool ans3 = solve(grid,row+1,col+2,expected + 1,n);
        bool ans4 = solve(grid,row+2,col+1,expected + 1,n);
        bool ans5 = solve(grid,row+2,col-1,expected + 1,n);
        bool ans6 = solve(grid,row+1,col-2,expected + 1,n);
        bool ans7 = solve(grid,row-1,col-2,expected + 1,n);
        bool ans8 = solve(grid,row-2,col-1,expected + 1,n);

        return ans1|| ans2 || ans3|| ans4 || ans5|| ans6 || ans7|| ans8 ;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {

        return solve(grid,0,0,0,grid.size());
        
    }
};