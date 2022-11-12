//  A - ^{-1}

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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
    }
    for ( int i = 0 ; i < n ; i++ ) {
        if ( a[i] == x ) {
            cout << i + 1 << endl;
            return;
        }
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