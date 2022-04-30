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
    vi a(n+1), id(n+1);
    for(int i= 0; i< n; i++) cin >> a[i+1];
    for(int i= 0; i< n; i++)
        id[a[i+1]]= i+1;
    int cnt= 0;
    for(int i= 1; i<= n; i++){
        if(a[i] != i){
            cnt++;
            swap(id[i], id[a[i]]);
            a[id[a[i]]]= a[i];
            a[i]= i;
        }
    }
    cout << cnt;
    return 0;
}
