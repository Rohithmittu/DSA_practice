 vector<int> find(int arr[], int n , int x )
    {
        // vector<int> ans;
        
        // for(int i = 0;i<n;i++){
        //     if(arr[i] == x){
        //         ans.push_back(i);
        //     }
        // }
        // int m = ans.size();
        
        // if(ans.empty()){
        //     return {-1,-1};
        // }else{
        //     return {ans[0],ans[m-1]};
        // }
        vector<int> ans(2, -1);
        
        // Find the first occurrence of x
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                ans[0] = mid;
                right = mid - 1; 
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    
        // Find the last occurrence of x
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                ans[1] = mid;
                left = mid + 1; 
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }