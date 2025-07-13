
int rec(int n, int i, vector<vector<int>> &points){

    if (n == 0){
        // No more days left.
        return 0;
    }

    // Merit points of ith task on nth day.
    int ans = points[n - 1][i - 1];
    int mx = 0;
    
    if (i == 1){
        mx = max(rec(n - 1, 2, points), rec(n - 1, 3, points));
    }

    if (i == 2){
        mx = max(rec(n - 1, 1, points), rec(n - 1, 3, points));
    }

    if (i == 3){
        mx = max(rec(n - 1, 1, points), rec(n - 1, 2, points));
    }

    return ans + mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int ans = 0;
    ans = max(ans, rec(n, 1, points));
    ans = max(ans, rec(n, 2, points));
    ans = max(ans, rec(n, 3, points));

    return ans;
}




// ************************************************************************************************************************************