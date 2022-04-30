#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int n; cin >> n;
    if(n== 1){
        int x; cin >> x;
        cout << max(x, 0);
        return 0;
    }
    vector<ll> a(n);
    for(auto &i: a) cin >> i;
    vector<ll> dp(n);
    dp[0]= max(a[0], (ll)0);
    dp[1]= max(a[1], (ll)0);
    for(int i= 2; i< n; i++){
        dp[i]= max(dp[i-2]+a[i], (ll)0);
        dp[i-1]= max(dp[i-1], dp[i-2]);
    }

    cout << max(dp[n-1], dp[n-2]);
    return 0;
}
