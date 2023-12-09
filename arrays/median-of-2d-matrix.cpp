int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> ans;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            ans.push_back(matrix[i][j]);
        }
    }

    sort(ans.begin(),ans.end());

    int size = ans.size();

    return ans[size/2];
}