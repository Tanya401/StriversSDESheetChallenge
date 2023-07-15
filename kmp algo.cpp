#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    int ssize = s.size();
    int psize = p.size();
    for (int i = 0; i < ssize - psize + 1; i++) {
      if (s.substr(i, p.size()) == p)
        return true;
    }
    return false;
}