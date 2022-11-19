//  H - Highest Hill

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define sz(x) (int)(x).size()
#define rep(i, a, b) for ( int i = a ; i < b ; i++ )
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void precompute() {

}

void work() {
    ll n;
    cin >> n;
    vector<ll> a(n+2, 0);
    a[n+1] = 1e18;
    rep(i, 1, n+1) cin >> a[i];
    ll ans = 0;
    ll i = 1, j = 1, k = 1;
    while ( i <= n && j <= n && k <= n ) {
        while ( a[j] <= a[j+1] && j <= n ) {
            j++;
        }
        k = j;
        while ( a[k] >= a[k+1] && k <= n ) {
            k++;
        }
        // i is the starting point, j is the middle, and k is the end
        if ( i != j && j != k && i != k ) {
            ans = max(ans, min(a[j]-a[i], a[j]-a[k]));
        }
        i = k;
        j = k;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}
