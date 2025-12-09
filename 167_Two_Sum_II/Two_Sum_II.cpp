#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = 0, r = numbers.size() -1, two_sum;
		while(l<r){
			two_sum = numbers[l] + numbers[r];
			if(two_sum == target) {
			break;
			}
			if (two_sum < target){
				l++;
			}else{
				r--;
			}
		}
		return vector<int>{l + 1, r + 1}; 
	}
};

//test runnder
int main() {
	Solution sol;

	// Example input (you can change this)
	vector<int> numbers = {2, 7, 11, 15};
	int target = 9;

	vector<int> result = sol.twoSum(numbers, target);

	cout << "Result: [" << result[0] << ", " << result[1] << "]" << endl;

	return 0;
}
