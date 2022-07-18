#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_subset_sum (vector<int>& nums, vector<int>& res, int index, int sum) {
    if (index == nums.size()) {
        res.push_back(sum);
        return;
    }
    find_subset_sum(nums,res,index+1,sum+nums[index]);
    find_subset_sum(nums,res,index+1,sum);
}

int main () {
    vector<int> nums = {1,2,3};
    vector<int> res;
    find_subset_sum(nums,res,0,0);
    for (int n : res) {
        cout << n << endl;
    }
    return 0;
}