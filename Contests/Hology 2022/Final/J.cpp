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
    string s;
    cin >> s;
    vector<ll> ori(s.size());
    for ( int i = 0 ; i < s.size() ; i++ ) {
        ori[i] = (ll)(s[i] - '0');
    }
    vector<ll> copy = ori;
    sort(all(copy), greater<>());
    do {
        if ( ori == copy ) continue;
        ll diff = 0;
        for ( int i = 0 ; i < ori.size() ; i++ ) {
           if ( ori[i] != copy[i] ) diff++;
        }
        if ( diff == 2 ) {
            if ( copy[copy.size()-1] % 2 == 0 ) {
                ll ans = 0;
                for ( int j = 0 ; j < copy.size() ; j++ ) {
                    ans *= 10;
                    ans = ( ans + copy[j] );
                }
                cout << ans << endl;
                return;
            }
        }
    } while (prev_permutation(all(copy)));
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}