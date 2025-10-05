class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int st = 0, end = m - 1;

        while (st < n && end >= 0) {

            if (target == matrix[st][end]) {
                return true;

            } else if (target < matrix[st][end]) {
                end--;
            } else {
                st++;
            }
        }

        return false;
    }
};