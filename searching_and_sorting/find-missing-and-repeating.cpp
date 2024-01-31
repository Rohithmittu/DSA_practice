//   unordered_map<int,int>m;
    //     vector<int> ar(2);
    //     for(int i=0;i<n;i++)
    //     {
    //         m[arr[i]]++;
    //     }
    //     for(int i=0;i<=n;i++)
    //     {
    //         if(m[i]>1)
    //         {
    //             ar[0]=i;
    //         }
    //         if(m[i]==0)
    //         {
    //             ar[1]=i;
    //         }
    //     }
    //     return ar;
    vector<int> ans(2);
        int i;
        
        // Iterate over the array to find the first element
        for (i = 0; i < n; i++) {
            // If the element is positive, make it negative
            // to mark it as visited
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            else
                // If the element is already negative, it is a duplicate
                // Store it as the first element in the answer vector
                ans[0] = abs(arr[i]);
        }
        
        // Iterate over the array to find the second element
        for (i = 0; i < n; i++) {
            // If the element is positive, it is the missing element
            // Store it as the second element in the answer vector
            if (arr[i] > 0) ans[1] = i + 1;
        }
        
        return ans;