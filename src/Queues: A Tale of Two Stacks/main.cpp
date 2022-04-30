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
    int qu; cin >> qu;
    deque<int> dq;
    while(qu--){
        int q; cin >> q;
        if(q== 1){
            int val; cin >> val;
            dq.push_back(val);
        }
        else if(q== 2){
            dq.pop_front();
        }
        else{
            cout << dq.front() << "\n";
        }
    }
    return 0;
}
