string longestPalin (string s) {
        int n=s.size();
        int start=0,end=0,maxl=1;
        
        //odd length
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n)
            {
                if(s[l]!=s[r])
                {
                    break;
                }
                l--;
                r++;
            }
            int len=r-l-1;
            if(len>maxl)
            {
                maxl=len;
                start=l+1;
                end=r-1;
            }
        }
        
        //even length
        for(int i=0;i<n;i++)
        {
            int l=i,r=i+1;
            while(l>=0 && r<n)
            {
                if(s[l]!=s[r])
                {
                    break;
                }
                l--;
                r++;
            }
            int len=r-l-1;
            if(len>maxl)
            {
                maxl=len;
                start=l+1;
                end=r-1;
            }
        }
        
        return s.substr(start,maxl);
    }


// 1)The function starts by initializing some variables:

// 2)n represents the size of the input string s.
// start and end are the indices that track the start and end positions of the longest palindromic substring found so far.
// maxl keeps track of the maximum length of a palindrome found.


// 3)The code then proceeds to find palindromic substrings of odd length by iterating over the string s:

// For each index i, it initializes two pointers l and r to i.
// It then checks if s[l] and s[r] are equal. If not, it breaks out of the loop.


// 4)If they are equal, it expands the palindrome by decrementing l and incrementing r until the characters at s[l] and s[r] are no longer equal or the boundaries of the string are reached.


// 5)After expanding, it calculates the length of the palindrome as r - l - 1 (subtracting 1 to exclude the extra increment of r and decrement of l after the last valid palindrome character).

// 6)If the length of the palindrome is greater than maxl, it updates maxl, start, and end accordingly.
//      The code then proceeds to find palindromic substrings of even length by iterating over the string s:

 
// 7)For each index i, it initializes two pointers l and r to i and i+1 respectively.

// 8)It then checks if s[l] and s[r] are equal. If not, it breaks out of the loop.


// 9)If they are equal, it expands the palindrome by decrementing l and incrementing r until the characters at s[l] and s[r] are no longer equal or the boundaries of the string are reached.
// After expanding, it calculates the length of the palindrome as r - l - 1.

// 10)If the length of the palindrome is greater than maxl, it updates maxl, start, and end accordingly.

// Finally, the code returns the substring from start to start + maxl using the substr function, which represents the longest palindromic substring found in the input string s.

// The code utilizes the concept of expanding around centers to find palindromes of odd and even lengths. By checking for palindromes of both lengths, it ensures that the longest palindromic substring is found and returned.