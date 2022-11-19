//
// Created by Tyrone Matthew on 11/11/2022.
// Tennis Game
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
    ll k, s, n;
    cin >> k >> s >> n;
    if ( k * s > n ) {
        cout << "NO" << endl;
        return;
    }
    if ( k == 2 ) {
        if ( n % 2 == 0 ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    else if ( k * s <= n ) {
        if ( s == 1 ) {
            if ( n - k <= k - 2 ) {
                cout << "YES" << endl;
            } else if (n % 2 == (k+(k-2)) % 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "YES" << endl;
        }
    } else {
        cout << "NO" << endl;
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