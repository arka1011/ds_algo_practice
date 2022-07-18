#include <iostream>
#include <vector>

void find_combis (int nums[], int n, int sum, std::vector<std::vector<int>>& res, int index, std::vector<int>& temp) {
    if (index == n) {
        if (sum == 0) {
            res.push_back(temp);
        }
        return;
    }
    if (nums[index] <= sum) {
        temp.push_back(nums[index]);
        find_combis(nums,n,sum-nums[index],res,index,temp);
        temp.pop_back();
    }
    find_combis(nums,n,sum,res,index+1,temp);
}

void find_combis_with_sum (int nums[], int n, int sum, std::vector<std::vector<int>>& res) {
    std::vector<int> temp;
    find_combis(nums,n,sum,res,0,temp);
}

int main () {
    int nums[] = {1,2,3,4};
    int sum = 5;
    std::vector<std::vector<int>> res;
    find_combis_with_sum(nums,4,sum,res);
    for (auto x : res) {
        for (auto y : x) {
            std::cout << y;
        }
        std::cout << std::endl;
    }
    return 0;
}