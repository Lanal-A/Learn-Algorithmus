#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()){
            return 0;
        }
        int  m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m , vector<int>(n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n; j++){
                if( !i || !j || matrix[i][j] == '0'){
                    dp[i][j] = matrix[i][j] - '0'; //check if the square is in the first column or the first row, or the square is simply '0'
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1; //the square will be limited by its left, upper and upper-left neighbors.


                }
                ans = max(dp[i][j],ans);
            }
        }
        return ans * ans;
  }
};

int main() {
    Solution sol;

    vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    vector<vector<char>> matrix2 = {
        {'0','1'},
        {'1','0'}
    };

    vector<vector<char>> matrix3 = {
        {'0'}
    };

    cout << "Test case 1: " << sol.maximalSquare(matrix1) << endl; // Expected: 4
    cout << "Test case 2: " << sol.maximalSquare(matrix2) << endl; // Expected: 1
    cout << "Test case 3: " << sol.maximalSquare(matrix3) << endl; // Expected: 0

    return 0;
}
