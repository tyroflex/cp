//  B - Misjudge the Time

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
    ll h, m;
    cin >> h >> m;

    while ( true ) {
        ll ch = (h/10)*10+(m/10);
        ll cm = (h%10)*10+(m%10);
        if (ch >= 0 && ch < 24 && cm >= 0 && cm < 60 ) {
            cout << h << " " << m << endl;
            return;
        }
        m++;
        if ( m == 60 ) {
            h++;
            m = 0;
        }
        if ( h == 24 ) h = 0;
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
