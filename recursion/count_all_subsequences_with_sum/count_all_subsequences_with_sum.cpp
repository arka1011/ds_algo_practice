#include <iostream>
#include <vector>

int subSqs(int nums[], int n, int target_sum, int& sum, std::vector<std::vector<int>>& res, int index) {
    if (index == n) {
        if (sum == target_sum)
            return 1;
        return 0;
    }
    sum+=nums[index];
    int l = subSqs(nums,n,target_sum,sum,res,index+1);
    sum-=nums[index];
    int r = subSqs(nums,n,target_sum,sum,res,index+1);
    return l+r;
}

int find_all_subsequences (int nums[], int n, int target_sum, std::vector<std::vector<int>>& res) {
    int sum = 0;
    return subSqs(nums,n,target_sum,sum,res,0);
}

int main () {
    int nums[] = {1,2,1};
    int sum = 3;
    std::vector<std::vector<int>> res;
    int count = find_all_subsequences(nums,3,3,res);
    std::cout << "count: " << count << std::endl;
    return 0;
}