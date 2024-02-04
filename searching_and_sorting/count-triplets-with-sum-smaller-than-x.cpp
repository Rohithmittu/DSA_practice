long long countTriplets(long long arr[], int n, long long sum)
	{
	    int ans = 0;
	    sort(arr,arr+n);
	    for(int i = 0;i<n;i++){
	        int j = i+1;
	        int k = n-1;
	        while(k>j){
	            int curr_sum = arr[i] + arr[j] + arr[k];
	            if(curr_sum >= sum){
	                k--;
	            }else{
	                ans = ans + k - j;
	                j++;
	            }
	        }
	    }
	    return ans;

	}