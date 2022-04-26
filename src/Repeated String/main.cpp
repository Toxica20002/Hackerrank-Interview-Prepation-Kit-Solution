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
    string s; cin >> s;
    ll n; cin >> n;
    int len= sz(s);
    ll k= n/len;
    ll ans= 0;
    for(auto &i: s){
        if(i=='a') ans++;
    }
    ans*= k;
    for(int i= 0; i< abs(n-k*len); i++) {
        if (s[i] == 'a') ans++;
    }
    cout << ans;
    return 0;
}
