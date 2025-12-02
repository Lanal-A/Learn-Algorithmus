#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int start = prices[0];
        int len = prices.size();
        for(int i = 1;i<len; i++){
            if(start < prices[i]){
                max += prices[i] - start;
            }
            start = prices[i];
        }
        return max;
    }
};

// Helper to print vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

// Test runner
void runTest(const vector<int>& prices, int expected) {
    Solution s;
    vector<int> input = prices;
    int result = s.maxProfit(input);

    cout << "Input Prices = ";
    printVector(prices);
    cout << "\nExpected: " << expected 
         << " | Got: " << result 
         << (result == expected ? "  ✓" : "  ✗")
         << "\n\n";
}

int main() {
    cout << "Running Tests...\n\n";

    runTest({7,1,5,3,6,4}, 7);         // Buy 1, sell 5 -> Buy 3, sell 6
    runTest({1,2,3,4,5}, 4);           // Buy at 1, sell at 5
    runTest({7,6,4,3,1}, 0);           // No profit possible
    runTest({2,1,2,0,1}, 2);           // Small zigzag case
    runTest({1}, 0);                   // Single element

    return 0;
}
