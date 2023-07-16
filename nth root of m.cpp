long long prod(int a,int b,int m){
  long long ans = 1;
  for (int i = 1; i <= a; i++) {
    ans *= b;
    if(ans > m) return 2;
  }
  if(ans == m)return 1;
  return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int start = 1, end = m;
  while(start<=end){
    int mid = (start+end)/2;
    long long res = prod(n,mid,m);
    if(res==1) return mid;
    else if(res == 2) end = mid-1;
    else start = mid+1;
  }
  return -1;
}