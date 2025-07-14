/* Merge Sorted Array */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j < n; j++) { // This loop copies all elements from nums2 into the end of nums1, starting from index m.
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end()); // This line sorts the entire nums1 array using the standard C++ library sort, which gives you the final sorted array.
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
