#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef tree<pii,null_type,less<>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    indexed_set s;
    int n, k; cin >> n >> k;
    vi a(n);
    for(auto &i: a) cin >> i;
    for(int i= 0; i< k; i++)
        s.insert(pii(a[i], i));

    int cnt= 0;

    for(int i= k; i< n; i++){
        if(k&1){
            int mid= (k-1)/2;
            auto x = *s.find_by_order(mid);
            if(x.first*2 <= a[i])
                cnt++;
        }
        else{
            int mid= k/2;
            auto x = *s.find_by_order(mid);
            int sum = x.first;
            x = *s.find_by_order(mid-1);
            sum+= x.first;
            if(sum <= a[i])
                cnt++;
        }
        s.erase(pii(a[i-k], i-k));
        s.insert(pii(a[i], i));
    }
    cout << cnt;
    return 0;
}
