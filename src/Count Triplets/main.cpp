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
    int n, r; cin >> n >> r;
    unordered_map<ll, ll> dic;
    vi a(n), mark(n);
    for(int i= 0; i< n; i++){
        cin >> a[i];
        dic[a[i]]++;
        if(a[i]%r== 0 && dic.count(a[i]/r))
            mark[i]= dic[a[i]/r];
    }

    if(r== 1){
        ll ans= 0;
        for(auto &i: dic){
            ll temp = i.second;
            temp*= i.second-1;
            temp*= i.second-2;
            ans+= temp/6;
        }
        cout << ans;
        return 0;
    }

    dic.clear();
    ll ans= 0;

    for(int i= 0; i< n; i++){
        if(a[i]%r== 0) ans+= dic[a[i]/r];
        dic[a[i]]+= mark[i];
    }

    cout << ans;
    return 0;
}
