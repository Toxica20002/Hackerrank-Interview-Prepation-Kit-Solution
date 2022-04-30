#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);

    int na, nb, nc;
    cin >> na >> nb >> nc;
    vector<ll> a, b, c;
    set<ll> sa, sb, sc;
    for(int i= 0; i< na; i++){
        ll x; cin >> x;
        sa.insert(x);
    }

    for(int i= 0; i< nb; i++){
        ll x; cin >> x;
        sb.insert(x);
    }

    for(int i= 0; i< nc; i++){
        ll x; cin >> x;
        sc.insert(x);
    }
    for(auto &i: sa) a.push_back(i);
    for(auto &i: sb) b.push_back(i);
    for(auto &i: sc) c.push_back(i);

    ll ans= 0;
    for(int i= 0; i< nb; i++){
        if(i && b[i-1]== b[i]){
            continue;
        }
        ans+= ll(std::lower_bound(a.begin(), a.end(), b[i]+1)-a.begin())*
              ll(std::lower_bound(c.begin(), c.end(), b[i]+1)-c.begin());
    }
    cout << ans;
    return 0;
}
