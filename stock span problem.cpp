#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    int n = price.size();
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    for (int i = 0; i < n; i++) {
        while (st.top() != -1 && price[st.top()] <= price[i]) {
            st.pop();
        }
        if (st.top() == -1) {
            ans.push_back(i + 1);
        } else {
            ans.push_back(i - st.top());
        }
        st.push(i);
    }
    return ans;
}
