#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{

    
    // Sort intervals based on their start times
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        // If the current interval overlaps with the previous one, merge them
        if (intervals[i][0] <= result.back()[1]) {
            result.back()[1] = std::max(result.back()[1], intervals[i][1]);
        } else {
            // If there is no overlap, add the current interval to the result
            result.push_back(intervals[i]);
        }
    }

    return result;

     

}