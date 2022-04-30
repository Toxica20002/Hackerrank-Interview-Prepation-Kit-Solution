#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi solve(vi &a){
    vi range(sz(a)), left(sz(a)), right(sz(a));
    stack<int> st;
    int n= sz(a)-1;
    for(int i= 1; i<= n; i++){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(st.empty()) left[i]= 0;
        else left[i]= st.top();
        st.push(i);
    }

    stack<int>().swap(st);
    for(int i= n; i>= 1; i--){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if(st.empty()) right[i]= n+1;
        else right[i]= st.top();
        st.push(i);
    }

    for(int i= 1; i<= n; i++){
        range[i]= right[i]-left[i]-1;
    }
    return range;
}

inline bool cmp(const pii &lhs, const pii &rhs){
    return (lhs.second== rhs.second)? lhs.first > rhs.first : lhs.second < rhs.second;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int n; cin >> n;
    vi a(n+2);
    for(int i= 1; i<= n; i++) cin >> a[i];
    vi range = solve(a);
    vector<pii> temp(n);
    for(int i= 0; i< n; i++){
        temp[i]= pii(a[i+1], range[i+1]);
    }
    sort(all(temp), cmp);
    vector<pii> temp1;
    temp1.push_back(temp[0]);
    for(int i= 1; i< n; i++){
        if(temp[i-1].second== temp[i].second) continue;
        while(temp1.back().first < temp[i].first) temp1.pop_back();
        temp1.push_back(temp[i]);
    }

    vector<int> ans;
    int j= 1;
    for(int i= 0; i< sz(temp1); i++){
        for(; j<= temp1[i].second; j++)
            ans.push_back(temp1[i].first);
    }
    sort(all(ans), greater<>());
    for(auto &i: ans)
        cout << i << " ";
    return 0;
}
