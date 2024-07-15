#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100000];
bool visited[100000];

void dfs(int n) {
    visited[n] = true;
    for (int i : adj[n]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1); // Because the graph is undirected
    }

    vector<int> path;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            path.push_back(i);
        }
    }

    int numPath = path.size();
    cout << numPath - 1 << endl;
    for (int i = 1; i < numPath; i++) {
        cout << path[i - 1]+1 << " " << path[i]+1 << endl;
    }

    return 0;
}
