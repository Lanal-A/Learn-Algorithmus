/* Merge Sorted Array */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = m-- + n-- - 1;
    while (m >= 0 && n >= 0) {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
        nums1[pos--] = nums2[n--];
    }
}
};

void runTest(vector<int> nums1, int m, vector<int> nums2, int n) {
    Solution sol;
    nums1.resize(m + n);  // ensure nums1 has enough space
    sol.merge(nums1, m, nums2, n);
    for (int x : nums1) cout << x << " ";
    cout << endl;
}

// Test algorithmus
int main() {
    runTest({1,2,3}, 3, {2,5,6}, 3);
    runTest({}, 0, {2,5,6}, 3);
    runTest({1}, 1, {}, 0);
    runTest({}, 0, {1}, 1);
    return 0;
}
