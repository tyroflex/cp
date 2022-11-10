//  B - Maximum Cost Deletion

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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<char> d(n);
    for ( char &c : d ) cin >> c;
    auto it = unique(all(d));
    d.resize(distance(d.begin(), it));
    if ( b >= 0 ) {
        cout << ( a * n ) + ( b * n ) << endl;
    } else {
        cout << ( a * n ) + ( b * (ll)((d.size()/2)+1) ) << endl;
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
