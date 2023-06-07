#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini = prices[0];
    int maxp = INT_MIN;
    for(int i=0;i<prices.size();i++){
        mini = min(mini,prices[i]);
        int cost = prices[i] - mini;
        maxp = max(maxp,cost);
    }
    return maxp;
}