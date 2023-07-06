#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    //find freq of all elements, sort freq in descending order, print k most 
    //frequent elements

    unordered_map<int,int> mp;
    for(auto it:arr) mp[it]++;

    priority_queue<pair<int,int>> pq;
    for(auto it:mp){
        pq.push({it.second,it.first});
        }
    vector<int> ans;
    while(k-- && !pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
  sort(ans.begin(),ans.end());
    return ans;
}