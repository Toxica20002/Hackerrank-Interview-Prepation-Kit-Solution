#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool cmp(const pii &lhs, const pii &rhs){
    return (lhs.first== rhs.first)? lhs.second < rhs.second : lhs.first < rhs.first;
}

ll it[int(4e5)+5];

void update(int id, int l, int r, int i){
    if(i < l || r < i)
        return;

    if(l== r){
        it[id]++;
        return;
    }

    int mid = (l+r)/2;
    update(id*2, l, mid, i);
    update(id*2+1, mid+1, r, i);

    it[id] = it[id*2] + it[id*2+1];
}

ll get(int id, int l, int r, int u, int v){
    if(v < l || r < u)
        return 0;
    if(u<= l && r<= v){
        return it[id];
    }
    int mid = (l+r)/2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

ll solve(int a[], int n, int maxE){
    ll inversions = 0;
    int i= 0, j= n-1;
    while(j>i){
        swap(a[i], a[j]);
        i++;
        j--;
    }

    memset(it, 0, sizeof(it));

    for(int i= 0; i< n; i++){
        inversions+= get(1, 1, maxE, 1, a[i]-1);
        update(1, 1, maxE, a[i]);

    }
    return inversions;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);

    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        pii val[n];
        for(int i= 0; i< n; i++){
            cin >> val[i].first;
            val[i].second = i;
        }
        sort(val, val+n, cmp);
        int Arr[n];
        int cnt= 1;
        Arr[val[0].second]= cnt;
        for(int i= 1; i< n; i++){
            if(val[i].first!= val[i-1].first)
                cnt++;
            Arr[val[i].second]= cnt;
        }
        cout << solve(Arr,n, cnt) << '\n';
    }

    return 0;
}
