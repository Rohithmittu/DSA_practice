class Solution {
public:
    string countAndSay(int n) {


        // if(n == 1){
        //     return "1";
        // }
        
        // string x;
        // string tmp = countAndSay(n-1);

        // int cnt = 1;

        // for(int i = 0;i < tmp.size()-1; i++){
        //     if(tmp[i] == tmp[i+1]){
        //         cnt++;
        //     }else{
        //         x = x + (to_string(cnt) + tmp[i]);
        //         cnt = 1;
        //     }
        // }

        // return (x+to_string(cnt) + tmp[tmp.size() - 1]);

        if (n == 1) {
        return "1";
        }

        std::string prev = countAndSay(n - 1);
        std::stringstream result;

        for (size_t i = 0; i < prev.length(); ++i) {
            char currentDigit = prev[i];
            int count = 1;

            // Count consecutive digits
            while (i + 1 < prev.length() && prev[i] == prev[i + 1]) {
                ++count;
                ++i;
            }

            // Append count and digit to result
            result << count << currentDigit;
        }

        return result.str();
            
        }
};