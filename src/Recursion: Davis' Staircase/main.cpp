#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int step[40];

int solve(int n){
    if(n < 0)
        return 0;
    if(step[n])
        return step[n];
    return step[n]= solve(n-1) + solve(n-2) + solve(n-3);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    step[0]= 1;
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
