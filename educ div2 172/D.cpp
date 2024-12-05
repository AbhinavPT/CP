#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

bool comp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if (p1.second.first != p2.second.first)
        return p1.second.first < p2.second.first;  // Sort by l (increasing)
    return p1.second.second >= p2.second.second;    // For equal l, sort by r (decreasing)
}

void findScore(int n, vector<pair<int, int>> arr) {
    set<int> s;
    vector<pair<int, pair<int, int>>> l1, l2;
    vector<int> ans(n, 0);

        unordered_map<pair<int, int>, int> segmentCount;
    for (auto& seg : arr) {
        segmentCount[seg]++;
    }

    // Prepare the first sorted list (for right intervals)
    for (int i = 0; i < n; i++) {
        l1.push_back({i, {arr[i].first, arr[i].second}});
    }
    sort(l1.begin(), l1.end(), comp);

    // Process for right intervals
    for (int i = 0; i < n; i++) {
        int r = l1[i].second.second;
        if (s.lower_bound(r) != s.end()) {
            int R = *s.lower_bound(r);
            ans[l1[i].first] += R - r;
        }
        s.insert(r);
    }

    // Clear set and prepare the second sorted list (for left intervals)
    s.clear();
    for (int i = 0; i < n; i++) {
        l2.push_back({i, {-arr[i].second, -arr[i].first}});
    }
    sort(l2.begin(), l2.end(), comp);

    // Process for left intervals
    for (int i = 0; i < n; i++) {
        int l = l2[i].second.second;
        if (s.lower_bound(l) != s.end()) {
            int L = *s.lower_bound(l);
            ans[l2[i].first] += L-l;
        }
        s.insert(l);
    }

    // Output the results
    for (int a : ans) {
        cout << a << endl;
    }
}

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        findScore(n, arr);
    }
    return 0;
}
