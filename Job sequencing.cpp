#include <bits/stdc++.h> 
static bool cmp(vector<int>&a,vector<int>&b){
    if((a[1]>b[1]) || (a[1]==b[1] && a[0]>=b[0])) return true;
    return false;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),cmp);
    int maxi = -1;
    for(int i=0;i<jobs.size();i++){
        maxi = max(maxi,jobs[i][0]);
    }
    vector<int> slot(maxi+1,-1);

    int count = 0, profit = 0;
    for(int i=0;i<jobs.size();i++){
        for(int j=jobs[i][0];j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                count++;
                profit += jobs[i][1];
                break;
            }
        }
    }
  return profit;
}
