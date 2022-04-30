#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dx[]= {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]= {-1, 0, 1, -1, 1, -1, 0, 1};

int ans= 0, n, m;

void dfs(vector<vi> &mx, int x, int y, vector<vi> &mark, int &cnt){
    mark[x][y]= 1;
    for(int i= 0; i< 8; i++){
        int xx= x+ dx[i];
        int yy= y+ dy[i];
        if(xx < 0 || xx== n || yy< 0 || yy== m) continue;
        if(mark[xx][yy] || !mx[xx][yy]) continue;
        dfs(mx, xx, yy, mark, ++cnt);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    cin >> n >> m;
    vector<vi> mx(n, vi(m));
    vector<vi> mark(n, vi(m));
    for(auto &i: mx)
        for(auto &j: i) cin >> j;
    for(int i= 0; i< n; i++){
        for(int j= 0; j< m; j++){
            if(mark[i][j] || !mx[i][j]) continue;
            int cnt= 1;
            dfs(mx, i, j, mark, cnt);
            ans= max(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}
