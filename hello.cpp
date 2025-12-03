// // #include <bits/stdc++.h>
// #include <iostream>   // header for input/output

// using namespace std;  // so we can use cout without std::

// int main() {
//     int x;
//     cin >> x;
//     cout << "Hello, World!  " << x << endl;  // print to console
//     return 0;  // exit program

// }

// // to run any file go to the directory in which the file is present and run it

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    // int n;
    // cin >> n;

    map<int, int> mpp;

    vector<int> ans;
    vector<int> nums1 = {10,10};
    vector<int> nums2 = {10};

    for (int i : nums2)
    {
        mpp[i]++;
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (mpp.count(nums1[i])){
            //   cout<<mpp[nums1[i]]<<" ";
            ans.push_back(nums1[i]);
            mpp[nums1[i]]--;
            if (mpp[nums1[i]]==0)
                mpp.erase(nums1[i]);
        }
    }
    for (int i : ans)
    {
        cout << i << " ";
    }

    // return 0;
}
