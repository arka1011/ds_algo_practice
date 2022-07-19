#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_subsets(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int index) {
    res.push_back(temp);
    for (int i=index; i<nums.size(); i++) {
        if (i>index && nums[i]==nums[i-1])
            continue;
        temp.push_back(nums[i]);
        find_subsets(nums,res,temp,i+1);
        temp.pop_back();
    }
}

int main () {
    vector<int> nums = {1,3,2};
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(),nums.end());
    find_subsets(nums,res,temp,0);
    for (auto v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}