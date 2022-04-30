#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char c[] = {'A', 'B'};

int solve(string s, int b){
    int ans= 0, i= 0;
    while(1){
        if(i== sz(s))
            break;
        if(s[i]== c[b]){
            b= b^1;
            i++;
            continue;
        }
        i++;
        ans++;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        cout << min(solve(s, 0), solve(s, 1)) << "\n";
    }
    return 0;
}
