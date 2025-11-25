#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>   // for accumulate

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left to right
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i] < ratings[i - 1]) {
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution sol;

    vector<int> ratings1 = {1, 0, 2};
    cout << "Test 1: " << sol.candy(ratings1) << endl;  // Expected: 5

    vector<int> ratings2 = {1, 2, 2};
    cout << "Test 2: " << sol.candy(ratings2) << endl;  // Expected: 4

    vector<int> ratings3 = {1,3,4,5,2};
    cout << "Test 3: " << sol.candy(ratings3) << endl;  // Expected: 11

    vector<int> ratings4 = {1,2,87,87,87,2,1};
    cout << "Test 4: " << sol.candy(ratings4) << endl;  // Expected: 13

    return 0;
}
