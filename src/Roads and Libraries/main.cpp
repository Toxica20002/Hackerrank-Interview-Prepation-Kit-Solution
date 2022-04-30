#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(vector<vi> &edges, int u, vi &mark, int label){
    if(mark[u]) return;
    mark[u]= label;
    for(auto &v: edges[u]){
        dfs(edges, v, mark, label);
    }
}

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void dfs(vector<vi> &graph, int u, int &no_edges, vi &mark){
    if(mark[u])
        return;
    mark[u]++;
    no_edges++;
    for(auto &v: graph[u]){
        dfs(graph, v, no_edges, mark);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    //freopen("input.txt", "r", stdin);
    int tc; cin >> tc;
    while(tc--){
        int n, m;
        ll c_road, c_lib;
        cin >> n >> m >> c_lib >> c_road;
        vector<vector<int>> graph(n, vi());
        UF tree(n);
        for(int i= 0; i< m; i++){
            int u, v; cin >> u >> v;
            u--;
            v--;
            if(tree.join(u, v)){
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        vi mark(n, 0);
        ll ans= 0;
        for(int i= 0; i< n; i++){
            if(!mark[i]){
                int no_edges= 0;
                dfs(graph, i, no_edges, mark);
                ans+= min((no_edges-1)*c_road+c_lib, c_lib*no_edges);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
