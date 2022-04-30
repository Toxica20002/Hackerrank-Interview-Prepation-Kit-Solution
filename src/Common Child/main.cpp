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
    string a, b; cin >> a >> b;
    a= " " + a;
    b= " " + b;

    vector<vi> dp(sz(a), vector<int> (sz(b), 0));
    for(int i= 1; i< sz(a); i++){
        for(int j= 1; j< sz(b); j++){
            if(a[i]== b[j]){
                dp[i][j]= dp[i-1][j-1]+1;
            }
            else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[sz(a)-1][sz(b)-1];
    return 0;
}
