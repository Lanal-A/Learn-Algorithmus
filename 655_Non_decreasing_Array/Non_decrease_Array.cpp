#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
public:
	bool checkPossibility(vector<int>& nums) {
	int cnt = 0;
	for(int i = 1; i < nums.size() && cnt<=1 ; i++){
		if(nums[i-1]>nums[i]){
			cnt++;
			if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];
			else nums[i] = nums[i-1];
		}
	}
		return cnt<=1;
	}
};

//test runner
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {4, 2, 3},
        {4, 2, 1},
        {3, 4, 2, 3},
        {5, 7, 1, 8},
        {1, 2, 3, 4},
        {1, 5, 4, 6, 7}
    };

    for (auto test : tests) {
        vector<int> nums = test; // copy
        bool result = sol.checkPossibility(nums);
        printVector(test);
        cout << "  ->  " << (result ? "true" : "false") << endl;
    }

    return 0;
}
