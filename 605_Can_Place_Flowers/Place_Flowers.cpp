#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < (int)flowerbed.size(); i++) {
            bool left = i == 0 || flowerbed[i - 1] == 0;
            bool right = i == (int)flowerbed.size() - 1 || flowerbed[i + 1] == 0;

            if (left && right && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};

int main() {
    // Example test
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    Solution sol;
    bool result = sol.canPlaceFlowers(flowerbed, n);

    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}
