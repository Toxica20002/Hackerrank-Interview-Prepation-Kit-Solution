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
    int n; cin >> n;
    vi a(n);
    for(auto &i: a) cin >> i;
    vi dp(n, (int)1e8);
    dp[0]= 0;
    for(int i= 1; i< n; i++){
        if(a[i]) continue;
        if(!a[i-1]) dp[i] = min(dp[i-1]+1, dp[i]);
        if(!a[i-2]) dp[i] = min(dp[i-2]+1, dp[i]);
    }
    cout << dp[n-1];
    return 0;
}
