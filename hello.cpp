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

using namespace std;  

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n);


    int cnt = 0;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            v[i][j] = cnt;
            cnt++;
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << v[i][j];
        }
    }

    // return 0;


    


}
