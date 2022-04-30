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
    int n; cin >> n;
    int a[n];
    for(int i= 0; i< n; i++)
        cin >> a[i];

    int cnt= 0;
    for(int i= 0; i< n-1; i++){
        for(int j= i+1; j< n; j++){
            if(a[i] > a[j]){
                cnt++;
                swap(a[i], a[j]);
            }
        }
    }
    printf("Array is sorted in %d swaps.\n", cnt);
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d\n", a[n-1]);
    return 0;
}
