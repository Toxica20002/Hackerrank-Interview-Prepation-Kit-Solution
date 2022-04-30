#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for((i) = a; (i) < (b); ++(i))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

vector<ll> val;
vector<ll> st;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void update(int id, int l, int r, int i, ll val){
    if(i < l || r < i)
        return;
    if(l== r){
        st[id]+= val;
        return;
    }
    int mid= (l+r)/2;
    update(id*2, l, mid, i, val);
    update(id*2+1, mid+1, r, i, val);
    st[id]= max(st[id*2], st[id*2+1]);
}

ll get(int id, int u, int v, int l, int r){
    if(v< l || r< u)
        return 0;
    if(u<= l && r<= v)
        return st[id];
    int mid= (l+r)/2;
    return max(get(id*2, u, v, l, mid),
               get(id*2+1, u, v, mid+1, r));
}

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b, int l, int r) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        update(1, l, r, a, val[b]);
        val[a]+= val[b];
        return true;
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(std::istream::failbit);
    int q; cin >> q;
    vector<pii> qu(q);
    unordered_map<ll, ll, custom_hash> dic;
    int cnt= 0;
    for(int i= 0; i< q; i++){
        cin >> qu[i].first >> qu[i].second;
        if(!dic.count(qu[i].first)) dic[qu[i].first]= cnt++;
        if(!dic.count(qu[i].second)) dic[qu[i].second]= cnt++;
        qu[i].first = dic[qu[i].first];
        qu[i].second = dic[qu[i].second];
    }

    UF tree(cnt);
    val.assign(cnt, 1);
    st.assign(4*cnt+5, 0);

    for(int i= 0; i< cnt; i++)
        update(1, 0, cnt-1, i, 1);

    for(int i= 0; i< q; i++){
        bool flag= tree.join(qu[i].first, qu[i].second, 0, cnt-1);
        cout << get(1, 0, cnt-1, 0, cnt-1) << "\n";
    }

    return 0;
}
