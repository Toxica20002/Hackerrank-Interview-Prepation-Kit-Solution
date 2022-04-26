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
    int n; cin >> n;
    vi a(n);
    for(auto &i: a){
        cin >> i;
    }
    sort(all(a));
    int i= 0, j= 0;
    int ans= 0;
    while(i< n){
        j= i;
        int cnt= 0;
        while(j< n && a[j]== a[i]){
            j++;
            cnt++;
        }
        ans+= cnt>>1;
        i= j;
    }
    cout << ans;
    return 0;
}
