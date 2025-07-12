#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {

  unordered_map<int,int> count;

  for(int i = 0;i< str.length();i++){
    count[str[i]]++;
  }
  for (int i=0; i<str.length(); i++){

    if (count[str[i]]==1) return str[i];

  }

  return str[0];


}