#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve_slow(int index, string str, vector<string>& res) {
    if (index == str.length()) {
        res.push_back(str);
        return;
    }
    for (int i=index; i<str.length(); i++) {
        swap(str[i],str[index]);
        solve_slow(index+1,str,res);
        swap(str[i],str[index]);
    }
}

string getPermutation_slow(int n, int k) {
    vector<string> res;
    string str;

    for (int i=1; i<=n; i++) {
        str += to_string(i);
    }

    solve_slow(0,str,res);
    sort(res.begin(), res.end());

    return res[k-1];
}

string getPermutation_fast(int n, int k) {

    string res;
    int fact = 1;
    vector<int> nums;

    for (int i=1; i<n; i++) {
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);

    k = k-1;
    while(true) {
        res += to_string(nums[k/fact]);
        nums.erase(nums.begin()+(k/fact));
        if (nums.size() == 0) {
            break;
        }
        k %= fact;
        fact /= nums.size();
    }

    return res;
}

int main () {

    int n = 3, k = 6;
    string ans = getPermutation_slow(n, k);
    cout << "The Kth permutation sequence (slow with recursion) is " << ans << endl;

    ans = getPermutation_fast(n, k);
    cout << "The Kth permutation sequence (fast w/o recursion) is " << ans << endl;
    return 0;
}