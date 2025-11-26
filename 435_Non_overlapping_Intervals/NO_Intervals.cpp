#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int removed = 0, prev_end = intervals[0][1];
    for (int i = 1; i < (int)intervals.size(); ++i) {
        if (intervals[i][0] < prev_end) {
            ++removed;
        } else {
            prev_end = intervals[i][1];
        }
    }
    return removed;
}
};

// ---------------- TEST RUNNER ----------------

void runTest(vector<vector<int>> intervals) {
    Solution s;
    int result = s.eraseOverlapIntervals(intervals);

    cout << "Input: [";
    for (auto &v : intervals) {
        cout << "[" << v[0] << "," << v[1] << "], ";
    }
    cout << "]\n";

    cout << "Minimum intervals to remove: " << result << "\n\n";
}

int main() {
    runTest({{1,2}, {2,3}, {3,4}, {1,3}});
    runTest({{1,2}, {1,2}, {1,2}});
    runTest({{1,2}, {2,3}});
    runTest({{1,100}, {11,22}, {1,11}, {2,12}});

    return 0;
}
