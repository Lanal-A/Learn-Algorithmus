#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        // Sort the balloons based on their end coordinates
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int prevEnd = points[0][1];

        // Count the number of non-overlapping intervals
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > prevEnd) {
                arrows++;
                prevEnd = points[i][1];
            }
        }

        return arrows;
    }
};

// Simple test runner
void runTest(vector<vector<int>> balloons) {
    Solution s;
    cout << "Input: ";
    for (auto &b : balloons) {
        cout << "[" << b[0] << "," << b[1] << "] ";
    }
    cout << "\nOutput arrows needed: " 
         << s.findMinArrowShots(balloons) << "\n\n";
}

int main() {
    runTest({{10,16},{2,8},{1,6},{7,12}});
    runTest({{1,2},{3,4},{5,6},{7,8}});
    runTest({{1,2},{2,3},{3,4},{4,5}});
    runTest({{1,10},{2,3},{4,5},{6,7}});

    return 0;
}
