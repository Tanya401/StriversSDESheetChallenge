#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    //find the break point
    //swap with the first biggest and reverse the rest of the string
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(permutation[i]<permutation[i+1]) {
            ind=i;
            break;
        }
    }
    if (ind == -1) {
      reverse(permutation.begin(), permutation.end());
    }
    else{
        for(int i=n-1;i>=0;i--){
            if(permutation[i]>permutation[ind]){
                swap(permutation[i],permutation[ind]);
                break;
            }
        }
        reverse(permutation.begin()+ind+1,permutation.end());
    }
    return permutation;

}