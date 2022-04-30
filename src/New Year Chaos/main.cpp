#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

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
        int n; cin >> n;
        bool flag= true;
        vi a(n);
        for(auto &i: a) cin >> i;
        indexed_set s;
        ll ans= 0;
        for(int i= n; i>= 1; i--){
            if(a[i-1] > i){
                if(a[i-1]-i > 2) {
                    flag = false;
                    break;
                }
            }
            ans+= s.order_of_key(a[i-1]);
            s.insert(a[i-1]);
        }
        if(flag){
            cout << ans << "\n";
        }
        else
            cout << "Too chaotic\n";
    }
    return 0;
}
