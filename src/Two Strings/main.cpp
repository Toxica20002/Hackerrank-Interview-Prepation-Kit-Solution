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
        unordered_map<char, bool> dic;
        for(auto &i: a)
            dic[i]= true;

        bool flag= false;
        for(auto &i: b)
            if(dic.count(i)) {
                flag= true;
                break;
            }

        if(flag) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
