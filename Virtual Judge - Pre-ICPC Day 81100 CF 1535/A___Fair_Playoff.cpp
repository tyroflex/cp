//  A - Fair Playoff

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
    vector<ll> d(4);
    for ( int i = 0 ; i < 4 ; i++ ) cin >> d[i];
    ll p1 = max(d[0], d[1]);
    ll p2 = max(d[2], d[3]);
    sort(all(d));
    if ( max(p1, p2) == d[3] && min(p1, p2) == d[2] ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
