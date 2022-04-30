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
        string s; cin >> s;
        unordered_map<string, int> dic;
        int n= sz(s);

        for(int i= 0; i< n; i++){
            for(int j= i; j< n; j++){
                string temp;
                for(int k= i; k<= j; k++)
                    temp+= s[k];
                sort(all(temp));
                dic[temp]++;
            }
        }
        ll ans= 0;
        for(auto &i: dic){
            ans+= i.second * (i.second-1)/2;
        }
        cout << ans << "\n";
    }
    return 0;
}
