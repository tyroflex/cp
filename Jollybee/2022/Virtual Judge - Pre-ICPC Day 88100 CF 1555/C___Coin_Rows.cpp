//  C - Coin Rows

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

ll m;

bool inside(ll x, ll y) {
    return x >= 0 && x < 2 && y >= 0 && y < m;
}

void work() {
    cin >> m;
    vector<vector<ll>> board(2+1, vector<ll>(m+1));
    for ( int i = 1 ; i <= 2 ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> board[i][j];
        }
    }
    vector<ll> pref(m+2);
    vector<ll> suff(m+2);
    pref[0] = 0;
    for ( int i = 1 ; i < m ; i++ ) {
        pref[i] = pref[i-1] + board[2][i];
    }
    suff[m+1] = 0;
    for ( int i = (int)m ; i >= 1 ; i-- ) {
        suff[i] = suff[i+1] + board[1][i];
    }
    ll ans = 1e18;
    for ( int i = 1 ; i <= m ; i++ ) {
//        cout << pref[i-1] << " " << suff[i+1] << endl;
        ans = min(ans, max(pref[i-1], suff[i+1]));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while ( t-- ) work();
    return 0;
}