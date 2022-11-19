//  N - New Time

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
    ll hour = (s[0]-'0')*10 + (s[1]-'0');
    ll minute = (s[3]-'0')*10 + (s[4]-'0');
    cin >> s;
    ll th = (s[0]-'0')*10 + (s[1]-'0');
    ll tm = (s[3]-'0')*10 + (s[4]-'0');
    ll ans = 1e18;
    for ( ll i = 0 ; i <= 48 ; i++ ) {
        for ( ll j = 0 ; j <= 180 ; j++ ) {
            ll ch = hour;
            ll cm = minute;
            cm += j;
            ch += cm/60;
            cm %= 60;
            ch += i;
            ch %= 24;
            if ( ch == th && cm == tm ) {
                ans = min(ans, i+j);
            }
        }
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
