#include <iostream>
#include <vector>

using namespace std;

void solve(int i, int j, vector<vector<int>> vis, vector<vector<int>>& maze, int n, string str , vector<string>& res) {
    if (i==n-1 && j==n-1) {
        res.push_back(str);
        return;
    }
    
    if (i+1<n && !vis[i+1][j] && maze[i+1][j]==1) {
        vis[i+1][j] = 1;
        solve(i+1,j,vis,maze,n,str+'D',res);
        vis[i+1][j] = 0;
    }

    if (j-1>=0 && !vis[i][j-1] && maze[i][j-1]==1) {
        vis[i][j-1] = 1;
        solve(i,j-1,vis,maze,n,str+'L',res);
        vis[i][j-1] = 0;
    }

    if (j+1<n && !vis[i][j+1] && maze[i][j+1]==1) {
        vis[i][j+1] = 1;
        solve(i,j+1,vis,maze,n,str+'R',res);
        vis[i][j+1] = 0;
    }

    if (i-1>=0 && !vis[i-1][j] && maze[i-1][j]==1) {
        vis[i-1][j] = 1;
        solve(i-1,j,vis,maze,n,str+'U',res);
        vis[i-1][j] = 0;
    }

}

vector<string> findPath(vector<vector<int>> maze, int n) {
    vector<string> res;
    vector<vector<int>> vis(n, vector<int>(n,0));

    solve(0,0,vis,maze,n,"",res);

    return res;
}

int main() {

    int n = 4;
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
        };

    vector<string> result = findPath(maze, n);

    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}