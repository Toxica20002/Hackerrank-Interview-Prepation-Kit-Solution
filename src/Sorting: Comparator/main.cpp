#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<string, int> pii;
typedef vector<int> vi;

bool cmp(const pii &lhs, const pii &rhs){
    return (lhs.second== rhs.second)? lhs.first < rhs.first : lhs.second > rhs.second;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &i: a){
        cin >> i.first >> i.second;
    }
    sort(all(a), cmp);
    for(auto &i: a){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
