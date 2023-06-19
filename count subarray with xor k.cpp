#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int,int> mp;
    mp[0]=1;
    int xorsum=0,count=0;
    for(int i=0;i<arr.size();i++){
      xorsum = xorsum^arr[i];
      int prefxor = xorsum^x;
      if(mp.find(prefxor)!=mp.end()) count+=mp[prefxor];
      mp[xorsum]++;
    }
    return count;
}