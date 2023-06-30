#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size();
    unordered_map<char,int> mp;
    int start = 0;
    int maxlen = INT_MIN;
    for(int i=0;i<n;i++){
     if(mp.find(input[i])!=mp.end() && mp[input[i]]>=start){
      start = mp[input[i]]+1;
     }
     mp[input[i]] = i;
     maxlen = max(maxlen,i-start+1);
    }
    return maxlen;

}