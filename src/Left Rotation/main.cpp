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
    int n, m; cin >> n >> m;
    m%= n;
    deque<int> dq(n);
    for(auto &i: dq) cin >> i;
    for(int i= 0; i< m; i++){
        dq.push_back(dq.front());
        dq.pop_front();
    }
    for(auto &i: dq)
        cout << i << " ";
    return 0;
}
