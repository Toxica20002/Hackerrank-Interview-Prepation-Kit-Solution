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
    vi a(n);
    for(auto &i: a) cin >> i;
    sort(all(a));
    int ans= abs(a[1]-a[0]);
    for(int i= 2; i< n; i++)
        ans= min(ans, abs(a[i]-a[i-1]));
    cout << ans;
    return 0;
}
