#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_permutsI (vector<int>& nums, vector<vector<int>>& res, int mark[], vector<int>& temp) {
    if (temp.size() == nums.size()) {
        res.push_back(temp);
    }
    for (int i=0; i<nums.size(); i++) {
        if (!mark[i]) {
            mark[i] = 1;
            temp.push_back(nums[i]);
            find_permutsI(nums,res,mark,temp);
            temp.pop_back();
            mark[i] = 0;
        }
    }
}

void find_permutsII (vector<int>& nums, vector<vector<int>>& res, int index) {
    if (index == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i=index; i<nums.size(); i++) {
        swap(nums[index],nums[i]);
        find_permutsII(nums,res,index+1);
        swap(nums[index],nums[i]);
    }
}

int main () {
    vector<int> nums = {1,3,1};
    vector<vector<int>> res;
    vector<int> temp;
    int mark[nums.size()];
    for (int i=0; i<nums.size(); i++)
        mark[i] = 0;
    //find_permutsI(nums,res,mark,temp);
    find_permutsII(nums,res,0);
    for (auto v : res) {
        for (int n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}