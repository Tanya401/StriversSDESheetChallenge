#include <bits/stdc++.h> 
  bool static cmp(pair<int,int>&a, pair<int,int>&b) {
         double r1 = (double) a.second / (double) a.first;
         double r2 = (double) b.second / (double) b.first;
         return r1 > r2;
      }
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),cmp);
    double val = 0;
    for(int i=0;i<n;i++){
        if(items[i].first<=w){
            w = w-items[i].first;
            val = val + items[i].second;
        }
        else{
            val += (static_cast<double>(items[i].second) / static_cast<double>(items[i].first)) * w;
            break;
        }
    }
    return val;
}