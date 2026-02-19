// class Solution
// {
// public:
//     set<vector<int>> s;
//     void solve(vector<int> &can, int target, int idx, vector<vector<int>> &ans, vector<int> &temp)
//     {

//         if (idx == can.size() || target < 0)
//         {
//             return;
//         }

//         if (target == 0)
//         {
//             if (s.find(temp) == s.end())
//             {
//                 ans.push_back(temp);
//                 s.insert(temp);
//             }
//             return;
//         }

//         temp.push_back(can[idx]);
//         // include
//         solve(can, target - can[idx], idx + 1, ans, temp);

//         // include-multiple
//         solve(can, target - can[idx], idx, ans, temp);
//         temp.pop_back();

//         // exlcude
//         solve(can, target, idx + 1, ans, temp);
//     }

//     vector<vector<int>> combinationSum(vector<int> &can, int target)
//     {

//         vector<vector<int>> ans;
//         vector<int> temp;
//         solve(can, target, 0, ans, temp);

//         return ans;
//     }
// };

class Solution {
public:
    void solve(vector<int>& can, int target, int idx, vector<vector<int>>& ans,
               vector<int>& temp) {
                
        if (idx == can.size()) {
            if (target == 0) {
                ans.push_back(temp);
                return;
            }
        }

        if (target < 0 || idx == can.size()) {
            return;
        }

        // Include (reuse allowed)
        temp.push_back(can[idx]);
        solve(can, target - can[idx], idx, ans, temp);

        temp.pop_back();

        // Exclude
        solve(can, target, idx + 1, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& can, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
        solve(can, target, 0, ans, temp);

        return ans;
    }
};