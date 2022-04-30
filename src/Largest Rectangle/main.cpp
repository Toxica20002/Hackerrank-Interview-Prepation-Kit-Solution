#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> solve(vector<ll> &h, int n){
    stack<ll> st;
    vector<ll> a(n+2);

    for(int i= 1; i<= n; i++){
        while(!st.empty() && h[st.top()] >= h[i])
            st.pop();
        if(st.empty())
            a[i]= 0;
        else
            a[i]= st.top();
        st.push(i);
    }

    return a;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int n; cin >> n;
    vector<ll> a(n+2, 0);
    for(int i= 1; i<= n; i++)
        cin >> a[i];
    vector<ll> left= a, right= a;
    reverse(all(right));
    left = solve(left, n);
    right = solve(right, n);
    reverse(all(right));
    for(int i= 1; i<= n; i++)
        right[i]= n+1-right[i];
    ll ans= 0;
    for(int i= 0; i< n; i++){
        ans= max(ans, a[i]*(right[i]-left[i]-1));
    }
    cout << ans;
    return 0;
}
