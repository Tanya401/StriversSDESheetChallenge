#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.size()!=str2.size()) return false;
    unordered_map<char,int> mp;
    mp.clear();
    for(auto it:str1) mp[it]++;
    
    for(int i=0;i<str2.size();i++){
      if(mp.find(str2[i])==mp.end() || mp[str2[i]] == 0) return false;
       mp[str2[i]]--;
    }
    return true;
}