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
        deque<char> dq;
        bool flag= true;
        for(auto &i: s){
            if(i== '(' || i== '[' || i== '{')
                dq.push_back(i);
            else{
                if(dq.empty()){
                    flag = false;
                    break;
                }
                if(dq.back()== '(' && i== ')')
                    dq.pop_back();
                else if(dq.back()== '[' && i== ']')
                    dq.pop_back();
                else if(dq.back()== '{' && i== '}')
                    dq.pop_back();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(!flag || !dq.empty())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
