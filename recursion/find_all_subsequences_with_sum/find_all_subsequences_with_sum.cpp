#include <iostream>
#include <vector>

void subSqs(int nums[], int n, int target_sum, int& sum, std::vector<std::vector<int>>& res, std::vector<int>& temp, int index) {
    if (index == n) {
        if (sum == target_sum)
            res.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    sum+=nums[index];
    subSqs(nums,n,target_sum,sum,res,temp,index+1);
    sum-=nums[index];
    temp.pop_back();
    subSqs(nums,n,target_sum,sum,res,temp,index+1);
}

void find_all_subsequences (int nums[], int n, int target_sum, std::vector<std::vector<int>>& res) {
    std::vector<int> temp;
    int sum = 0;
    subSqs(nums,n,target_sum,sum,res,temp,0);
}

int main () {
    int nums[] = {1,2,1};
    int sum = 3;
    std::vector<std::vector<int>> res;
    find_all_subsequences(nums,3,3,res);
    for (auto s : res) {
        for (auto x : s)
            std::cout << x;
        std::cout << std::endl;
    }
    return 0;
}