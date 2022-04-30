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
        string a, b; cin >> a >> b;
        int n= sz(a), m= sz(b);
        vector<vi> dp(n+1, vi(m+1, 0));
        dp[0][0]= 1;
        int delta= 'A' - 'a';
        for(int i= 0; i< n; i++){
            for(int j= 0; j<= m; j++){
                if(dp[i][j]){
                    if(j< m){
                        if(a[i]== b[j] || char(a[i]+delta)== b[j]) {
                            dp[i+1][j+1]= 1;
                            continue;
                        }
                    }
                    if(a[i] >= 'a' && a[i] <= 'z') dp[i+1][j]= 1;
                }
            }
        }
        if(dp[n][m]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
