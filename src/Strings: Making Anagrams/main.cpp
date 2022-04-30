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
    string a, b; cin >> a >> b;
    sort(all(a));
    sort(all(b));
    int i= 0, j= 0, k= 0;
    while(1){
        if(i== sz(a) || j== sz(b))
            break;
        if(a[i]== b[j]){
            k++;
            i++;j++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else j++;
    }
    cout << sz(a)+sz(b)-2*k;
    return 0;
}
