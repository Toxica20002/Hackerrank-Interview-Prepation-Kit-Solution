#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll calc(vector<ll> &a, ll x){
    ll sum= 0;
    for(auto &i: a)
        sum+= x/i;
    return sum;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    ll n, goal; cin >> n >> goal;
    vector<ll> a(n);
    for(auto &i: a) cin >> i;
    double l= 1, r= 1e18;
    for(int i= 0; i< int(1e3); i++){
        double mid= (l+r)/2;
        ll sum= calc(a, ll(mid));
        if(sum >= goal){
            r= mid;
        }
        else l= mid;
    }
    cout << ll(r);
    return 0;
}
