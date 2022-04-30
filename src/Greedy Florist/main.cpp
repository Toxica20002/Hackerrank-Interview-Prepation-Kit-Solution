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
    int n, k, t; cin >> n >> k;
    vector<ll> a(n);
    t= k;
    for(auto &i: a) cin >> i;
    sort(all(a), greater<>());
    ll ans= 0, cnt= 1;
    for(auto &i: a){
        if(!k){
            k= t;
            cnt++;
        }
        ans+= i*cnt;
        k--;
    }
    cout << ans;
    return 0;
}
