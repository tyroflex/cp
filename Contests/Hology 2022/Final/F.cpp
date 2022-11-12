//
// Created by Tyrone Matthew on 11/12/2022.
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

void precompute() {

}

void work() {
    ll n, in;
    ll mx = LLONG_MIN, mn = LLONG_MAX;
    cin >> n;
    map<ll, ll> storage;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> in;
        mx = max(mx, in);
        mn = min(mn, in);
        storage[in]++;
    }
    if ( mx == mn ) {
        cout << 0 << " " << ((n-1) * (n-2)) / 2 << endl;
    } else {
        cout << mx-mn << " " << storage[mx]  * storage[mn] << endl;
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