#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int num = 0;
    bool sign = false;
    for(int i=0;i<str.size();i++){
       if(str[i] == '-') {
           if(sign == true) continue;
           else sign = true;
       }
       if(str[i]>='0' && str[i]<='9') num = num*10+(str[i]-'0');
       else continue;
    }
    if(sign  == true) num *= -1;
    return num;
}