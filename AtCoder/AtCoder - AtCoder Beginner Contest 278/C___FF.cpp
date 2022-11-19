//  C - FF

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
//#define endl '\n'
#define all(x) (x).begin(), (x).end()

void precompute() {

}

map<ll, map<ll, ll>> m;

void work() {
    ll n, q;
    cin >> n >> q;
    while ( q-- ) {
        ll a, b, c;
        cin >> a >> b >> c;
        if ( a == 1 ) {
            m[b][c] = 1;
        }
        else if ( a == 2 ) {
            m[b][c] = 0;
        }
        else {
            if ( m[b][c] == 1 && m[c][b] == 1 ) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
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
