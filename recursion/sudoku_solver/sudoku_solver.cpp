#include <iostream>
#include <vector>

using namespace std;

bool isValid (vector<vector<char>>& puzz, int row, int col, char val) {
    for (int i=0; i<puzz.size(); i++) {
        if (puzz[row][0] == val) {
            return false;
        }
        if (puzz[i][col] == val) {
            return false;
        }
        if (puzz[3 * (row/3) + i/3][3 * (col/3) + i%3] == val) {
            return false;
        }
    }
    return true;
}

bool solve (vector<vector<char>>& puzz) {
    for (int r=0; r<puzz.size(); r++) {
        for (int c=0; c<puzz.size(); c++) {
            if (puzz[r][c] == '.') {
                for (char i='1'; i<='9'; i++) {
                    if (isValid(puzz,r,c,i)) {
                        puzz[r][c] = i;
                        if (solve (puzz))
                            return true;
                        else
                            puzz[r][c]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main () {
    vector<vector<char>> puzz = {

        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}

    };

    solve(puzz);
        	
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            cout<<puzz[i][j]<<" ";
            cout<<endl;
    }

    return 0;
}