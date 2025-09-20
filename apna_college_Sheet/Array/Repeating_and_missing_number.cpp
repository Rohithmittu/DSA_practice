class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> ans;
        unordered_set<int> s;
        int a,b;
        int expsum = 0,actsum = 0;
        int n = grid.size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                actsum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);

                }

                s.insert(grid[i][j]);

            }
        }

        expsum = (n*n) * (n*n + 1) / 2;
        b = expsum + a - actsum;
        ans.push_back(b);

        return ans;



        // // #2 

        // int n = grid.size();
        // int maxi = n * n;

        // // allocate with size maxi+1, initialized to 0
        // vector<int> hashh(maxi + 1, 0);

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         hashh[grid[i][j]]++;
        //     }
        // }

        // int repeating = -1, missing = -1;
        // for (int i = 1; i <= maxi; i++) {
        //     if (hashh[i] == 2)
        //         repeating = i;
        //     if (hashh[i] == 0)
        //         missing = i;
        // }

        // return {repeating, missing};
    }
}
}
;