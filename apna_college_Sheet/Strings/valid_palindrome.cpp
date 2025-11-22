class Solution {
public:

    // bool isvalid(char ch){
    //     if(ch >= '0' && ch <='9' || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
    //         return true;
    //     }

    //     return false;
    // }

    bool isPalindrome(string s) {

        int n = s.size();

        int i = 0,j = n-1;

        while(i < j){
            if(!isalnum(s[i])){
                i++;
                continue;

            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }

            if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }else{
                return false;
            }


        }

        return true;



        
    }
};