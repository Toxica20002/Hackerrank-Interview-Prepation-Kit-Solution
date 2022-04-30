#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


void dijkstra(vector<vector<ii>> &a, int n, int u) {
    priority_queue<ii, vector<ii>, greater<>> pq;
    vector<int> d(n, 1000111000);
    d[u] = 0;
    pq.push(ii(0, u));

    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (auto &i: a[u]) {
            int v = i.second;
            int uv = i.first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
    for (int i = 0; i < n; i++){
        if(i== u) continue;
        if (d[i] == 1000111000) cout << -1 << ' ';
        else cout << d[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int tc; cin >> tc;
    while(tc--){
        int n, m; cin >> n >> m;
        vector<vector<ii>> edges(n, vector<ii>());
        while(m--){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edges[u].push_back(ii(6, v));
            edges[v].push_back(ii(6, u));
        }
        int u; cin >> u; u--;
        dijkstra(edges, n, u);
    }
    return 0;
}
