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
    ll n, y;
    cin >> n >> y;
//    assert(n >= y);
    vector<ll> d(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> d[i];
        d[i] %= 2;
    }
    if ( y > n ) {
        cout << "SOK ASIK" << endl;
        return;
    }
    sort(all(d));
    queue<ll> window;
    ll cur = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( window.size() < y ) {
            window.push(d[i]);
            cur += d[i];
        } else {
            if ( cur % 2 == 1 ) {
                cout << "ASIK" << endl;
                return;
            }
            cur -= window.front();
            window.pop();
            cur += d[i];
            window.push(d[i]);
        }
    }
    if ( cur % 2 == 1 ) {
        cout << "ASIK" << endl;
    } else {
        cout << "SOK ASIK" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while ( t-- ) work();
    return 0;
}