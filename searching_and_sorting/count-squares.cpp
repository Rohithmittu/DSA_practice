int countSquares(int N) {
        
        int count = 0;
        
        for(int i = 1;i*i < N;i++){
            
            count++;
            
        }
        return count;
        
        // if(N == 1){
        //     return 0;
        // }
        
        // int start = 0;
        // int end = N;
        
        // int count = 0;
        // int mid = start + (end - start)/2;
        
        // while(start <= end){
            
        //     if(mid * mid == N){
        //         return mid-1;
        //     }
        //     else if(mid * mid < N){
        //         count = mid;
        //         start = mid + 1;
        //     }else{
        //         end = mid + 1;
        //     }
            
           
            
            
            
        // }
        // return count;
        
    }