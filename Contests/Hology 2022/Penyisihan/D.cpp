//
// Created by Tyrone Matthew on 11/5/2022.
//
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
    vector<ll> p1(n), p2(n);
    ll ans = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> p1[i];
    }
    for ( int i = 0; i < n; i++ ) {
        cin >> p2[i];
    }
    sort(all(p1)); sort(all(p2));
    for ( int i = 0 ; i < n ; i++ ) {
        ans = max(ans, abs(p2[i] - p1[i]));
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