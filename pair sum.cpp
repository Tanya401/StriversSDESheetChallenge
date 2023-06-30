#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
  //  unordered_map<int,int> mp;
  //  for(auto it:arr) mp[it]++;
   
  //  vector<vector<int>> ans;
  //  if(arr.empty()) return ans;
  //  for(int i=0;i<arr.size();i++){
  //    if(mp.find(s-arr[i])!=mp.end() && mp[arr[i]]>0 && mp[s-arr[i]]>0){
  //      if(arr[i]<s-arr[i])
  //      ans.push_back({arr[i],s-arr[i]});
  //      else
  //      ans.push_back({s-arr[i],arr[i]});
  //      mp[s-arr[i]]--;
  //    //mp[arr[i]]--;
  //    }
  //  }
  //  sort(ans.begin(),ans.end());
  //  return ans;


  vector<vector<int>> ans;
  for(int i=0;i<arr.size();i++){
    for(int j=i+1;j<arr.size();j++){
      if(arr[i]+arr[j]==s){
        if(arr[i]<arr[j]) ans.push_back({arr[i],arr[j]});
        else ans.push_back({arr[j],arr[i]});
      }
    }
  }
  sort(ans.begin(),ans.end());
  return ans;
}