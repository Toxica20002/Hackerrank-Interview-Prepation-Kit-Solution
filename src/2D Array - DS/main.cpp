#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n= 6;
    vector<vi> mx(n, vector<int> (n));
    for(auto &i: mx)
        for(auto &j: i) cin>> j;

    ll ans = int(-1e8);

    for(int i= 1; i<= 4; i++){
        for(int j= 1; j<= 4; j++){
            ll sum = mx[i][j];
            for(auto &k: {-1, 0, 1}){
                sum+= mx[i-1][j+k] + mx[i+1][j+k];
            }
            ans= max(ans, sum);
        }
    }
    cout << ans;
    return 0;
}
