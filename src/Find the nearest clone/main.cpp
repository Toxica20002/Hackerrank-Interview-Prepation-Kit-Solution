#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


int dijkstra(vector<vector<ii>> &a, int n, int u, vector<int> &ids, int id) {
    priority_queue<ii, vector<ii>, greater<>> pq;
    vector<int> d(n, 1000111000);
    d[u] = 0;
    pq.push(ii(0, u));
    int ans= 1000111000;
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
                if(ids[v]== id)
                    ans= min(ans, d[v]);
                pq.push(ii(d[v], v));
            }
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int n, m; cin >> n >> m;
    vector<vector<ii>> edges(n, vector<ii>());
    while(m--){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(ii(1, v));
        edges[v].push_back(ii(1, u));
    }
    vi a(n);
    int ans= 1000111000;
    for(auto &i: a) cin >> i;
    int id; cin >> id;
    for(int i= 0; i< n; i++){
        if(a[i]== id){
            ans= min(ans, dijkstra(edges, n, i, a, id));
        }
    }
    if(ans== 1000111000)
        cout << -1;
    else cout << ans;
    return 0;
}
