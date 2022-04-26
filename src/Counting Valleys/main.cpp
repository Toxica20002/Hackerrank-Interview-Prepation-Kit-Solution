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
    string s; cin >> s;
    int h= 0, pre= -1, cnt= 0;
    for(auto &i: s){
        if(i== 'U') h++;
        else h--;
        if(h> 0 && (pre< 0 || !pre)){
            pre= 1;
        }
        else if(h< 0 && (pre<0 || pre)) {
            pre = 0;
            cnt++;
        }
        else if(h== 0){
            pre= -1;
        }
    }
    cout << cnt;
    return 0;
}
