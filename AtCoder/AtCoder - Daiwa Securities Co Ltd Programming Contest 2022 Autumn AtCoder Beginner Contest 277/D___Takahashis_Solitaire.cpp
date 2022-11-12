//  D - Takahashi's Solitaire

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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll sum = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    vector<ll> grp;
    ll cur = 0;
    ll prev = a[0];
    for ( int i = 0 ; i < n ; i++ ) {
        if ( a[i] == prev || a[i] == prev + 1 ) {
            cur += a[i];
            prev = a[i];
        } else {
            grp.pb(cur);
            cur = a[i];
            prev = a[i];
        }
    }
    grp.pb(cur);
    if ( a[a.size()-1] == m-1 && a[0] == 0 ) {
        // looping
        if ( grp.size() == 1 ) {
            cout << sum - grp[0] << endl;
            return;
        } else {
            grp[0] += grp.back();
            grp.pop_back();
        }
    }
    ll ans = 1e18;
    for ( int i = 0 ; i < grp.size() ; i++ ) {
        ans = min(ans, sum-grp[i]);
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
