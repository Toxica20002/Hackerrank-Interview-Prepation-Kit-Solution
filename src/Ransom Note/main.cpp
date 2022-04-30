#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> a(n), b(m);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j= 0;
    bool flag = 0;
    for(auto &i: a){
        if(i== b[j]){
            j++;
        }
        if(j== m){
            flag= 1;
            break;
        }
    }

    cout << ((flag)? "Yes" : "No");
    return 0;
}
