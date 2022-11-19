//  E - Grid Filling

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
    ll H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<ll>> v(H+1, vector<ll>(W+1, 0));
    vector<vector<vector<ll>>> stat(N+1, vector<vector<ll>>(H+1, vector<ll>(W+1, 0)));
    vector<vector<vector<ll>>> pref(N+1, vector<vector<ll>>(H+1, vector<ll>(W+1, 0)));
    // O(N^3)
    vector<ll> counts(N+1);
    for ( int i = 1 ; i <= H ; i++ ) {
        for ( int j = 1 ; j <= W ; j++ ) {
            cin >> v[i][j];
            counts[v[i][j]]++;
            stat[v[i][j]][i][j] = 1;
            for ( int k = 0 ; k <= N ; k++ ) {
                pref[k][i][j] = stat[k][i][j] + pref[k][i-1][j] + pref[k][i][j-1] - pref[k][i-1][j-1];
            }
        }
    }
    for ( int i = 1 ; i <= H-h+1 ; i++ ) {
        for ( int j = 1 ; j <= W-w+1 ; j++ ) {
            ll ans = 0;
            for ( int k = 1 ; k <= N ; k++ ) {
                ll counter = counts[k] -
                        ( pref[k][i+h-1][j+w-1] -
                        pref[k][i-1][j+w-1] -
                        pref[k][i+h-1][j-1] +
                        pref[k][i-1][j-1] );
                if ( counter > 0 ) ans++;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}
