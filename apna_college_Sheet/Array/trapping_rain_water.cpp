class Solution {
public:
    int trap(vector<int>& height) {

        // int n = height.size();
        // int ans = 0;

        // for (int i = 1; i < n - 1; i++) {
            
        //     int maxl = 0;
        //     for (int j = 0; j <= i; j++)
        //         maxl = max(maxl, height[j]);

        //     int maxr = 0;
        //     for (int j = i; j < n; j++)
        //         maxr = max(maxr, height[j]);

        //     int p1 = min(maxl, maxr);

        //     ans += p1 - height[i];
        // }

        // return ans;


        // int n = height.size();
        // int ans = 0;

        // vector<int> maxl(n,0);
        // vector<int> maxr(n,0);

        // maxl[0] = height[0];
        // maxr[n-1] = height[n-1];

        // for(int i = 1;i<n;i++){
        //     maxl[i] = max(maxl[i-1],height[i]);
        // }

        // for(int i = n-2;i>=0;i--){
        //     maxr[i] = max(maxr[i+1],height[i]);
        // }

        // for(int i = 0;i<n;i++){
        //     int p1 = min(maxl[i],maxr[i]);
        //     ans += p1 - height[i];
        // }
        // return ans;

        int n = height.size();

        int ans = 0;
        int l = 0, r = n-1;

        int lmax = 0, rmax = 0;

        while(l < r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);

            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }else{
                ans += rmax - height[r];
                r--;
            }
        }

        return ans;




 
    }
};
