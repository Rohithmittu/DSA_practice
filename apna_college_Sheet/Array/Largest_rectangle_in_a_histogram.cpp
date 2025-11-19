class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // int ans = 0;
        // int n = heights.size();

        // for (int i = 0; i < n; i++) {
        //     int h = heights[i];
        //     for (int j = i; j < n; j++) {
        //         h = min(heights[j], h);

        //         int w = j - i + 1;

        //         int area = h * w;

        //         ans = max(ans, area);
        //     }
        // }

        // return ans;

        int n = heights.size();
        int ans = 0;

        stack<int> s;
        vector<int> right(n);
        vector<int> left(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (!s.empty()) {
                right[i] = s.top();
            } else {
                right[i] = n;
            }

            s.push(i);
        }

        while (!s.empty()) {

            s.pop();
        }

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            if (!s.empty()) {
                left[i] = s.top();
            } else {
                left[i] = -1;  // we cant put n because its the second paramenter that we use to substract 
            }

            s.push(i);
        }

        for (int i = 0; i < n; i++) {

            int h = heights[i];
            int w = right[i] - left[i] - 1;

            int area = h * w;
            ans = max(ans, area);
        }

        return ans;
    }
};