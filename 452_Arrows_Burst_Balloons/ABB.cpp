#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());                //original sorting
        int lastpoint = p[0][1];
        int arrows = 1;
        for (auto point : p) {
            if (point[0] > lastpoint) {
                arrows++;
                lastpoint = point[1];
            }
            lastpoint = min(point[1], lastpoint);
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
