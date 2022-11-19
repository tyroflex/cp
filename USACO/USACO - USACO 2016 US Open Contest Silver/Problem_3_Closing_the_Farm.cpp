//  Problem 3. Closing the Farm

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

vector<vector<ll>> adj(3001);
vector<bool> closed(3001, false);
vector<bool> visited;

void dfs( ll u ) {
    visited[u] = true;
    for ( auto v : adj[u] ) {
        if ( !visited[v] ) {
            dfs(v);
        }
    }
}

void work() {
    ll n, m;
    cin >> n >> m;
    while ( m-- ) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    visited = closed;
    dfs(1);
    bool can = true;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( !visited[i] ) {
            cout << "NO" << endl;
            can = false;
            break;
        }
    }
    if ( can ) cout << "YES" << endl;
    for ( int i = 1 ; i < n ; i++ ) {
        ll x;
        cin >> x;
        closed[x] = true;
        visited = closed;
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( visited[j] ) continue;
            dfs(j);
            break;
        }
        can = true;
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( !visited[j] ) {
                cout << "NO" << endl;
                can = false;
                break;
            }
        }
        if ( can ) cout << "YES" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
//    cin >> t;
    while ( t-- ) work();
    return 0;
}