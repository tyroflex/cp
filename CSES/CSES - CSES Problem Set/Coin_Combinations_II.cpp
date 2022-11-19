//  Coin Combinations II

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define endl '\n'
#define all(x) (x).begin(), (x).end()

void precompute() {

}

void work() {
    ll n, x;
    cin >> n >> x;
    vector<ll> money(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> money[i];
    }
    sort(all(money));
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 1 ; j <= x ; j++ ) {
            if ( j - money[i] >= 0 ) {
                dp[j] = dp[j] + dp[j-money[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}