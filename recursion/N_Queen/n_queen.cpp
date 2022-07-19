#include <iostream>
#include <vector>
using namespace std;

bool isValid (vector<string>& board, int r, int c) {
    for (int i=0; i<c; i++) {
        if (board[r][i] == 'Q') {
            return false;        
        }
    }
    for (int i=r, j=c; i>=0 && j>=0; i--,j--) {
        if (board[i][j] == 'Q') {
            return false;        
        }
    }
    for (int i=r, j=c; i<board.size() && j>=0; i++,j--) {
        if (board[i][j] == 'Q') {
            return false;        
        }
    }
    return true;
}

void place_Q (vector<string>& board, vector<vector<string>>& res, int col) {
    if (col == board.size()) {
        res.push_back(board);
    }
    for (int i=0; i<board.size(); i++) {
        if (isValid(board,i,col)) {
            board[i][col] = 'Q';
            place_Q(board,res,col+1);
            board[i][col] = '.';
        }
    }
}

vector<vector<string>> n_queen (int n) {
    vector<vector<string>> res;
    vector<string> board;
    string str = "";
    for (int i=0; i<n; i++) {
        str+='.';
    }
    for (int i=0; i<n; i++) {
        board.push_back(str);
    }
    place_Q(board,res,0);
    return res;
}

int main () {
    vector<vector<string>> res;
    res = n_queen(4);
    for (auto v : res) {
        for (auto c : v) {
            cout << c << endl; 
        }
        cout << endl;
    }
    return 0;    
}