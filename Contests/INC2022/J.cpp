//
// Created by Tyrone Matthew on 11/13/2022.
//
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

vector<ll> dist(100005, 1);

void precompute() {
    dist[0] = 0;
    ll diff = 3;
    ll diffchange = 3;
    for ( int i = 1 ; i < 100004 ; i++ ) {
        dist[i+1] = dist[i] + diff;
        diff += diffchange;
        diffchange++;
    }
}

void work() {
    set<ll> s;
    ll n;
    cin >> n;
    s.insert(0);
    s.insert(n+1);
    ll q;
    cin >> q;
    ll ans = dist[n];
//    cout << ans << endl;
    while ( q-- ) {
        ll k;
        cin >> k;
        if ( s.find(k) == s.end() ) {
            // removing effect of between k.
            auto it = s.upper_bound(k);
            ll r = *it;
            it--;
            ll l = *it;
//            cout << l << " " << r << endl;
            ans -= dist[r-l-1];
            // inserting k.
            s.insert(k);
            ans += dist[k-l-1] + dist[r-k-1];
        } else {
            // removing effect of k.
            s.erase(k);
            auto it = s.upper_bound(k);
            ll r = *it;
            it--;
            ll l = *it;
            ans -= dist[k-l-1] + dist[r-k-1];
            // inserting effect of removal of k.
            ans += dist[r-l-1];
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}