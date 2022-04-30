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
    int n, qu; cin >> n >> qu;
    vector<ll> a(n+1, 0);
    while(qu--){
        int l, r; ll val;
        cin >> l >> r >> val;
        a[r]+= val;
        a[l-1]-= val;
    }

    ll ans= 0, val= 0;
    for(int i= n; i> 0; i--){
        val += a[i];
        ans= max(ans, val);
    }
    cout << ans;
    return 0;
}
