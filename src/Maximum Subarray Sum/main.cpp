#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int tc; cin >> tc;
    while(tc--){
        ll n, m; cin >> n >> m;
        vector<ll> a(n);
        for(auto &i: a) cin >> i;
        a[0]%= m;
        for(int i= 1; i< n; i++)
            a[i]= (a[i-1]+ a[i])%m;
        set<ll> s;
        s.insert(0);
        ll ans= 0;
        for(int i= 0; i< n; i++){
            ans= max(ans, a[i]);
            auto it = s.lower_bound(a[i]+1);
            if(it!= s.end())
                ans= max((a[i]-*it+m)%m, ans);
            s.insert(a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
