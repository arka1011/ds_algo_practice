#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& graph, int N, int color[], int node, int col) {
    for (int i=0; i<N; i++) {
        if (i != node && graph[i][node] == 1 && color[i] == col) {
            return false;
        }
    }
    return true;
}

bool m_color(vector<vector<int>>& graph, int N, int m, int color[], int node) {
    if (node == N) {
        return true;
    }
    for (int i=1; i<=m; i++) {
        if (isValid(graph,N,color,node,i)) {
            color[node] = i;
            if (m_color(graph,N,m,color,node+1))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

int main () {

    const int N = 4;
    int m = 2;
    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int color[N];
    for (int i=0; i<N; i++) 
        color[i] = 0;

    if (m_color(graph,N,m,color,0))
        cout << "possible" << endl;
    else 
        cout << "not possible" << endl;;

    return 0;
}