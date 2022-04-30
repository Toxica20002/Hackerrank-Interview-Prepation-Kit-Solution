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
    vi a(n);
    for(auto &i: a) cin >> i;
    sort(all(a));
    int cnt= 0, w= 0;
    for(auto &i: a){
        if(w+i > k) break;
        cnt++;
        w+= i;
    }
    cout << cnt;
    return 0;
}
