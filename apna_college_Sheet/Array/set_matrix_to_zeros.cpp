class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int m = matrix[0].size();

        // vector<int> row(n, 0);
        // vector<int> col(m, 0);

        // // Step 1: Record which rows and cols have zeros
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (matrix[i][j] == 0) {
        //             row[i] = 1;
        //             col[j] = 1;
        //         }
        //     }
        // }

        // // Step 2: Set zeros based on recorded info
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (row[i] == 1 || col[j] == 1) {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // O(2*m*n)--TC
        // O(m) + O(n)--SC

        int n = matrix.size();
        int m = matrix[0].size();

        int col = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col = 0;
                    }
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                if (matrix[i][j] != 0) {

                    if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        if (col == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

        // TC - O(n^2);
        // SC- 1;
    }
};