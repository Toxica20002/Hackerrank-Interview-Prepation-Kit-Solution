#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

bool cmp(const pii &lhs, const pii &rhs){
    return (lhs.first== rhs.first)? lhs.second< rhs.second : lhs.first < rhs.first;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int tc; cin >> tc;
    while(tc--){
        ll money; cin >> money;
        int n;
        cin >> n;
        vector<pii> a(n);
        for(int i= 0; i< n; i++){
            cin >> a[i].first;
            a[i].second= i;
        }
        sort(all(a), cmp);
        int i, j;
        for(i= n-1; i>= 0; i--){
            j= (int)(lower_bound(all(a), pii(money-a[i].first,  0))-a.begin());
            if(j== n) continue;
            if(a[j].first+a[i].first== money){
                cout << min(a[j].second, a[i].second)+1 << " " << max(a[j].second, a[i].second)+1 << "\n";
                break;
            }
        }
    }
    return 0;
}
