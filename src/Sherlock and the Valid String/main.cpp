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

    string s; cin >> s;
    int i= 0, j= 0;
    vi a;
    sort(all(s));
    while(i< sz(s)){
        j= i;
        int cnt= 0;
        while(j< sz(s) && s[i]== s[j]){
            j++;
            cnt++;
        }
        a.push_back(cnt);
        i= j;
    }
    sort(all(a));
    ll sum= 0;
    for(auto &i: a)
        sum+= i-a[0];

    if(sum > 1)
        if(a[0]== 1){
            bool check = true;
            for(int i= 1; i< sz(a)-1; i++){
                if(a[i]!= a[i+1]){
                    check = false;
                    break;
                }
            }
            if(check){
                cout << "YES";
            }
            else cout << "NO";
        }
        else{
            cout << "NO";
        }
    else{
        cout << "YES\n";
    }
    return 0;
}
