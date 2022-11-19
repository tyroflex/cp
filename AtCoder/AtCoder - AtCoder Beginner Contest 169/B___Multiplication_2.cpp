//  B - Multiplication 2

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

ll MX = 1e18;

void work() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    __uint128_t ans = 1;
    for ( int i = 0 ; i < n ; i++ ) cin >> d[i];
    sort(all(d));
    for ( int i = 0 ; i < n ; i++ ) {
        ans *= d[i];
        if ( ans > MX ) {
            cout << -1 << endl;
            return;
        }
    }
    cout << (ll)ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}
