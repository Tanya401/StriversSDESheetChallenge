#include<bits/stdc++.h>


int maximumMeetings(vector<int> &start, vector<int> &finish)
{
vector<pair<int,pair<int,int>>> ans;
for(int i = 0;i < start.size();i++){
ans.push_back({finish[i],{i+1,start[i]}});
}
//sort the ans vector accoding to finish value


sort(ans.begin(),ans.end());

int e = -1;
int count = 0;

for(auto val : ans){
if(val.second.second > e){
count++;
e = val.first;
}
}
return count;

}