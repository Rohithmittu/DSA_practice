#include <bits/stdc++.h> 
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    std::vector<int> common_elements;
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size() && k < c.size()) {
        if (a[i] == b[j] && b[j] == c[k]) {
            common_elements.push_back(a[i]);
            i++;
            j++;
            k++;
        } else if (a[i] < b[j]) {
            i++;
        } else if (b[j] < c[k]) {
            j++;
        } else {
            k++;
        }
        int xx = a[i-1];

        while(a[i] == xx){
            i++;
        }

        int yy = b[j-1];

        while(b[j]==yy){
            j++;
        }

        int zz = c[k-1];

        while(c[k]==zz){
            k++;
        }
    }

    return common_elements;
    
}