class Solution {
public:
    bool search(vector<vector<int>>& matrix, int target, int row) {

        int n = matrix[0].size();

        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == matrix[row][mid]) {

                return true;

            } else if (target > matrix[row][mid]) {

                st = mid + 1;

            } else {

                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();

        int m = matrix[0].size();

        int st = 0, end = n - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][m - 1]) {

                return search(matrix, target, mid);

            } else if (target >= matrix[mid][m - 1]) {

                st = mid + 1;

            } else {

                end = mid - 1;
            }
        }

        return false;
    }
};