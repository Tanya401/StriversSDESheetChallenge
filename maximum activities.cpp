#include <bits/stdc++.h>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

int maximumActivities(std::vector<int>& start, std::vector<int>& finish) {
    int n = start.size();
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({start[i], finish[i]});
    }
    std::sort(v.begin(), v.end(), cmp);

    int count = 1;
    int prevFinish = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first >= prevFinish) {
            count++;
            prevFinish = v[i].second;
        }
    }

    return count;
}
