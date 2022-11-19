//  B - Array Reodering

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
    ll n, in;
    cin >> n;
    vector<ll> a;
    vector<ll> dv2;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> in;
        if ( in % 2 == 0 ) {
            dv2.pb(in);
        } else {
            a.pb(in);
        }
    }
    sort(all(a), greater<>());
    sort(all(dv2), greater<>());
    for (long long &i : a) {
        dv2.pb(i);
    }
    ll ans = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = i+1 ; j < n ; j++ ) {
            if ( __gcd(dv2[i], 2*dv2[j]) > 1 ) {
                ans++;
//                cout << dv2[i] << " " << dv2[j] << endl;
            }
        }
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