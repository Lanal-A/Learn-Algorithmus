#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &children, vector<int> &cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child_i = 0, cookie_i = 0;
    int n_children = children.size(), n_cookies = cookies.size();
    while (child_i < n_children && cookie_i < n_cookies) {
        if (children[child_i] <= cookies[cookie_i]) {
            ++child_i;
        }
        ++cookie_i;
    }
    return child_i;
}
};

/// ------------------------------------------------------
/// Test runner function to verify correctness of solution
/// ------------------------------------------------------
void runTest(vector<int> children, vector<int> cookies, int expected) {
    Solution s;
    int result = s.findContentChildren(children, cookies);

    cout << "children = ";
    for (int x : children) cout << x << " ";
    cout << "\ncookies  = ";
    for (int x : cookies) cout << x << " ";

    cout << "\nExpected = " << expected
         << ", Result = " << result
         << (result == expected ? "  ✔ Passed" : "  ✘ Failed")
         << "\n\n";
}

int main() {
    // Test 1 (Example case)
    runTest({1,2,3}, {1,1}, 1);

    // Test 2 (Enough cookies)
    runTest({1,2}, {1,2,3}, 2);

    // Test 3 (All cookies too small)
    runTest({2,3,4}, {1,1,1}, 0);

    // Test 4 (All children satisfied)
    runTest({1,1,1}, {2,2,2}, 3);

    // Test 5 (No children)
    runTest({}, {1,2,3}, 0);

    // Test 6 (No cookies)
    runTest({1,2,3}, {}, 0);

    // Test 7 (Mixed case)
    runTest({10,9,8,7}, {5,6,7,8}, 2);

    return 0;
}
