class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);

        // Step 2: merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                 // overlap → extend the last interval
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // no overlap → push new interval
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
