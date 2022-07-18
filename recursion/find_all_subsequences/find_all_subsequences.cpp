#include <iostream>
#include <vector>

void subSqs(std::string str, std::vector<std::string>& res, std::vector<char>& temp, int index) {
    if (index == str.length()) {
        res.push_back(std::string(temp.begin(), temp.end()));
        return;
    }
    temp.push_back(str[index]);
    subSqs(str,res,temp,index+1);
    temp.pop_back();
    subSqs(str,res,temp,index+1);
}

void find_all_subsequences (std::string str, std::vector<std::string>& res) {
    std::vector<char> temp;
    subSqs(str,res,temp,0);
}

int main () {
    
    std::string str = "abc";
    std::vector<std::string> res;
    find_all_subsequences(str,res);
    for (auto s : res) {
        std::cout << s << std::endl;
    }
    return 0;
}