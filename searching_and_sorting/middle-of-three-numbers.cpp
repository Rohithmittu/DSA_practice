int middle(int A, int B, int C){
        
        
      
      if (A < B){
          
        return (B < C)? B : max(A, C);
          
      }else{
          
        return (A < C)? A : max(B, C);
      }
    
    
        
}