#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    int i = 0;
    int j = 0;
    unordered_map<int,int> mp;
    int size = 0;
    int n = arr.size();
    vector<int> ans;
    while(j<n){
           mp[arr[j]]++;
           size++;
            if(size == k){
           ans.push_back(mp.size());
           mp[arr[i]]--;
           if(mp[arr[i]]==0) mp.erase(arr[i]);
           i++;
           size--;
       }
       j++;
    }
	return ans;
}
