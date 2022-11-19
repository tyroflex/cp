//  A - Shift

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
    ll n, k, in;
    cin >> n >> k;
    deque<ll> dq;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> in;
        dq.pb(in);
    }
    while ( k-- ) {
        dq.pop_front();
        dq.pb(0);
    }
    while ( !dq.empty() ) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}
