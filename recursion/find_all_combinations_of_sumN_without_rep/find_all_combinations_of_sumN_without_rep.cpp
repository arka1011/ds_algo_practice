#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_combis (vector<int>& nums, int sum, int index, vector<int>& temp, vector<vector<int>>& res) {
    if (sum == 0) {
        res.push_back(temp);
    }
    for (int i=index; i<nums.size(); i++) {
        if (i>index && nums[i] == nums[i-1])
            continue;
        if (sum < nums[i])
            break;
        temp.push_back(nums[i]);
        find_combis(nums,sum-nums[i],i+1,temp,res);
        temp.pop_back();
    }
}

vector<vector<int>> find_combis_helper(vector<int>& nums, int sum) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;
    find_combis(nums,sum,0,temp,res);
    return res;
}

int main () {
    vector<int> nums = {1,2,4,2,1,1}; 
    int sum = 6;
    vector<vector<int>> res = find_combis_helper(nums,sum);
    for (auto v : res) {
        for (int n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}