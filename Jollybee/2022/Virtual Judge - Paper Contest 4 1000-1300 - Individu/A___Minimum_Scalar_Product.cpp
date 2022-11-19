//  A - Minimum Scalar Product

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
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for ( ll &in : x ) cin >> in;
    for ( ll &in : y ) cin >> in;
    sort(all(x));
    sort(all(y), greater<>());
    ll ans = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        ans += (x[i]*y[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    for ( int i = 1 ; i <= t ; i++ ) {
        cout << "Case #" << i << ": ";
        work();
    }
    return 0;
}
