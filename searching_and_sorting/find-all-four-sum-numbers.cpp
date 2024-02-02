vector<vector<int> > fourSum(vector<int> &arr, int s) {
        
        if(arr.size()<4){
            return {};
        }
        
        vector<vector<int>> v;
        vector<vector<int>> v1;
        set<vector<int>> s1;
        
        sort(arr.begin(),arr.end());
        
        int sum=0;
        for(int i=0;i<arr.size()-3;i++){
            sum+=arr[i];
            for(int j=i+1;j<arr.size()-2;j++){
                sum+=arr[j];
                for(int k=j+1;k<arr.size()-1;k++){
                    sum+=arr[k];
                    int d=s-sum;
                    int start=k+1,end=arr.size()-1,mid;
                    while(start<=end){
                        mid=start+(end-start)/2;
                        if(arr[mid]==d){
                            v.push_back({arr[i],arr[j],arr[k],d});
                            break;
                        }
                        else if(arr[mid]>d)
                        end=mid-1;
                        else
                        start=mid+1;
                    }
                    sum-=arr[k];
                }
                sum-=arr[j];
            }
            sum-=arr[i];
        }
        if(v.size()==0){
            return v;
        }
        for(vector<int> x: v){
            s1.insert(x);
        }
        for(vector<int> x: s1){
            v1.push_back(x);
        }
        
        return v1;
    
        
    }