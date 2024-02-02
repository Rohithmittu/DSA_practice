vector<vector<int> > fourSum(vector<int> &arr, int s) {
        
        // if(arr.size()<4){
        //     return {};
        // }
        
        // vector<vector<int>> v;
        // vector<vector<int>> v1;
        // set<vector<int>> s1;
        
        // sort(arr.begin(),arr.end());
        
        // int sum=0;
        // for(int i=0;i<arr.size()-3;i++){
        //     sum+=arr[i];
        //     for(int j=i+1;j<arr.size()-2;j++){
        //         sum+=arr[j];
        //         for(int k=j+1;k<arr.size()-1;k++){
        //             sum+=arr[k];
        //             int d=s-sum;
        //             int start=k+1,end=arr.size()-1,mid;
        //             while(start<=end){
        //                 mid=start+(end-start)/2;
        //                 if(arr[mid]==d){
        //                     v.push_back({arr[i],arr[j],arr[k],d});
        //                     break;
        //                 }
        //                 else if(arr[mid]>d)
        //                 end=mid-1;
        //                 else
        //                 start=mid+1;
        //             }
        //             sum-=arr[k];
        //         }
        //         sum-=arr[j];
        //     }
        //     sum-=arr[i];
        // }
        // if(v.size()==0){
        //     return v;
        // }
        // for(vector<int> x: v){
        //     s1.insert(x);
        // }
        // for(vector<int> x: s1){
        //     v1.push_back(x);
        // }
        
        // return v1;
        
        if (a.size() < 4) return {};
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size() - 3; ++i) {
            // current element is greater than k then no quadruplet can be found
            if (a[i] > 0 && a[i] > k) break;
            // removing duplicates
            if (i > 0 && a[i] == a[i - 1]) continue;
            for (int j = i + 1; j < a.size() - 2; ++j) {
                // removing duplicates
                if (j > i + 1 && a[j] == a[j - 1]) continue;
    
                // taking two pointers
                int left = j + 1;
                int right = a.size() - 1;
                while (left < right) {
                    int old_l = left;
                    int old_r = right;
                    // calculate current sum
                    int sum = a[i] + a[j] + a[left] + a[right];
                    if (sum == k) {
                        // add to answer
                        ans.push_back({a[i], a[j], a[left], a[right]});
    
                        // removing duplicates
                        while (left < right && a[left] == a[old_l]) left++;
                        while (left < right && a[right] == a[old_r]) right--;
                    } else if (sum > k) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        return ans;
    
        
    }