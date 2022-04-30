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
    string s; cin >> s;
    vi a(n);
    int i= 0, j= 0;
    ll ans= 0;
    while(i< n){
        j= i;
        while(j< n && s[i]== s[j]){
            j++;
            a[i]++;
        }
        ans+= (a[i]+1)*a[i]/2;
        i= j;
    }
    for(i= 1; i< n; i++)
        if(s[i]== s[i-1]) a[i]= a[i-1];

    for(i= 1; i< n-1; i++){
        if(s[i+1]== s[i-1] && s[i+1] != s[i]){
            ans+= min(a[i-1], a[i+1]);
        }
    }
    cout << ans;
    return 0;
}
