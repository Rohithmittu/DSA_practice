long long int findSubarray(vector<long long int> &arr, int n ) {
        // long long int sum=0, counter=0; 
         
        //  //using map to store the prefix sum which has appeared already.
        // unordered_map<long long int,long long int>mp;
        
        // //iterating over the array.
        // for(int i=0;i<n;i++)
        // {
        //     //storing prefix sum.
        //     sum+=arr[i];
            
        //     //if prefix sum is zero that means we get a subarray with sum=0.
        //     if(sum==0) 
        //     {
        //         //incrementing the counter.
        //         counter++; 
        //     }
            
            
            
        //     //if prefix sum is already present in map then it is repeated 
        //     //which means there is a subarray whose summation is 0.
        //     if(mp.count(sum)!=0) 
        //     {
        //       //we add the value at prefix sum in map to counter.
        //       counter+=mp[sum]; 
        //     }
            
        //     //incrementing the count of prefix sum obtained in map.
        //     mp[sum]++; 
            
        // }
        //   //returning the counter.
        // return counter ;
        long long int ans=0;
        long long int psum=0;
        unordered_map<long long int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            psum+=arr[i];
            ans+=mp[psum];
            mp[psum]++;
        }
        return ans;
    }