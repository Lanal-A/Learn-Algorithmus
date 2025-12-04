#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	static bool comp(vector<int>& a, vector<int>& b){
		if(a[0] == b[0]) return a[1] < b[1];
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), comp);
		vector<vector<int>> ans;
		for(auto man : people){
			ans.insert(ans.begin()+man[1], man);
		}
		return ans;
	}
};

int main() {
    // Sample input
    vector<vector<int>> people = {
        {7, 0},
        {4, 4},
        {7, 1},
        {5, 0},
        {6, 1},
        {5, 2}
    };

    Solution s;
    vector<vector<int>> result = s.reconstructQueue(people);

    // Print the result
    cout << "Reconstructed Queue:" << endl;
    for (const auto& p : result) {
        // Print each pair: [h, k]
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    cout << endl;

    return 0;
}
