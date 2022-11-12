//  C - Ladder Takahashi

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
    ll n;
    cin >> n;
    map<ll, vector<ll>> adj;
    set<ll> vis;
    while ( n-- ) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<ll> q;
    q.push(1);
    while ( !q.empty() ) {
        ll u = q.front();
        q.pop();
        if ( vis.find(u) != vis.end() ) continue;
        vis.insert(u);
        for ( auto v : adj[u] ) {
            if ( vis.find(v) == vis.end() ) {
                q.push(v);
            }
        }
    }
    cout << (*vis.rbegin()) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}
