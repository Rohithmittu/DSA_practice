class Solution {
public:
    void solve(vector<int>& can, int target, int idx, vector<vector<int>>& ans,
               vector<int>& temp) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0 || idx == can.size()) {
            return;
        }

        for (int i = idx; i < can.size(); i++) {

            if (i > idx && can[i] == can[i - 1]) {
                continue;
            }

            temp.push_back(can[i]);
            solve(can, target - can[i], i + 1, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int target) {

        sort(can.begin(), can.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(can, target, 0, ans, temp);

        return ans;
    }
};