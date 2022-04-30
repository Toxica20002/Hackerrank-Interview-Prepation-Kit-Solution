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
    int tc; cin >> tc;
    while(tc--){
        unsigned long long int n, ans= 0, bit= 1;
        cin >> n;
        vi b;
        while(n){
            b.push_back(n&1);
            n>>= 1;
        }
        while(sz(b) != 32) b.push_back(0);
        for(auto &i: b){
            i^= 1;
            ans+= bit*i;
            bit<<= 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
