public:
    int maxSubStr(string str){
        //Write your code here
         int n=str.length();
    // To store the count of 0s and 1s
    int count0 = 0, count1 = 0;
 
    // To store the count of maximum
    // substrings str can be divided into
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            cnt++;
        }
    }
 
    // It is not possible to
    // split the string
    if (count0!=count1) {
        return -1;
    }
 
    return cnt;

    //  stack<int>st;
    //     int cnt=0;
    //     for(int i=0;i<str.size();i++){
    //         if(!st.empty()){
    //             if(st.top()!=str[i]){
    //                 st.pop();
    //                 if(st.empty()){
    //                  cnt++;
    //                 }
    //             }
    //             else{
    //                 st.push(str[i]);
    //             }
    //         }
    //         else{
    //             st.push(str[i]);
    //         }
    //     }
    //     return st.size()==0? cnt:-1;
    
    
    }
};