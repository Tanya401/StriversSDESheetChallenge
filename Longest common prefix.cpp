string findprefix(string a,string b){
    int n = a.size();
    int m = b.size();
    if(n==0) return b;
    int i=0,j=0;
    string res = "";
    while(i<n && j<m){
        if(a[i]==b[j]){
            res += a[i];
            i++;
            j++;
        }
        else break;
    }
    return res;
}
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string temp = "";
    for(int i=0;i<n;i++){
        temp = findprefix(temp,arr[i]);
        if(temp == "") return "";
    }
    return temp;
}


