//  Coin Combinations I

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
    ll n, k;
    cin >> n >> k;
    vector<ll> money(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> money[i];
    }
    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    for ( int i = 1 ; i <= k ; i++ ) {
        for ( int j = 0 ; j < n ; j++ ) {
            if ( i - money[j] >= 0 ) {
                dp[i] = dp[i] + dp[i-money[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[k] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}