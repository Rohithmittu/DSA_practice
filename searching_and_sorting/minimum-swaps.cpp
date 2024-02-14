int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    
	    vector<pair<int,int>>v;
	    for(int i = 0; i<n;i++){
	        v.push_back({nums[i],i});
	    }
	    
	    sort(v.begin(),v.end());
	    int count =0;
	    
	    for(int i = 0; i<n;i++){
	        if(i==v[i].second)
	         continue;
	        
	        else{
	            count++;
	            swap(v[v[i].second],v[i]);
	            i--;
	        }
	    }
	    return count;
	    
	    
	}