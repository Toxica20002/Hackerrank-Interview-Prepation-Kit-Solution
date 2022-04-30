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

    int n, k; cin >> n >> k;
    vi a;
    ll ans= 0;
    for(int i= 0; i< n; i++){
        int L, T; cin >> L >> T;
        if(T) a.push_back(L);
        else ans+= L;
    }

    sort(all(a));
    for(int i= 0; i< min(sz(a), k); i++){
        ans+= a[sz(a)-i-1];
    }
    if(sz(a)> k) {
        for(int i= 0; i< sz(a)-k; i++)
            ans-= a[i];
    }
    cout << ans;
    return 0;
}
