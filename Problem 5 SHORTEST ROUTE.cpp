#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<long long, int> mydtype;
const long long INF = LLONG_MAX;

vector<long long> dijkstra(int n, vector<vector<mydtype>>& adj, int start) {
    vector<long long> dist(n + 1, INF);
    priority_queue<mydtype, vector<mydtype>, greater<mydtype>> line;

    dist[start] = 0;
    line.push({0, start});

    while (!line.empty()) {
        long long d = line.top().first;
        int u = line.top().second;
        line.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            long long weight = adj[u][i].second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                line.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<mydtype>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c)); // Add edge from a to b with length c
    }

    vector<long long> shortest_paths = dijkstra(n, adj, 1);

    for (int i = 1; i <= n; ++i) {
        cout << (shortest_paths[i] == INF ? -1 : shortest_paths[i]) << " ";
    }

    cout << endl;
    return 0;
}
