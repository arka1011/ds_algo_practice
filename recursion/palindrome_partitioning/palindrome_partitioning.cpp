#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPal(string str, int st, int end) {
    while (st <= end) {
        if (str[st++] != str[end--]) {
            return false;
        }
    }
    return true;
}

void partition(int index, string str, vector<string>& path, vector<vector<string>>& res) {
    if (index == str.length()) {
        res.push_back(path);
        return;
    }
    for (int i=index; i<str.length(); i++) {
        if (isPal(str,index,i)) {
            path.push_back(str.substr(index,i-index+1));
            partition(i+1,str,path,res);
            path.pop_back();
        }
    }
}

vector<vector<string>> pal_part(string str) {
    vector<vector<string>> res;
    vector<string> path;

    partition(0,str,path,res);

    return res;
}

int main () {

    string s = "aabb";
    vector<vector<string>> ans = pal_part(s);
    int n = ans.size();
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto i: ans) {
        cout << "[ ";
        for (auto j: i) {
        cout << j << " ";
        }
        cout << "] ";
    }
  cout << "]";

    return 0;
}