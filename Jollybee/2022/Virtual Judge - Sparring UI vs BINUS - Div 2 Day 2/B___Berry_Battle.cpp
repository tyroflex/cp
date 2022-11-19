//  B - Berry Battle

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

vector<vector<ll>> adj(3e5+1);
vector<bool> vis(3e5+1);

void dfs( ll u , bool doPrint ) {
    vis[u] = true;
    if ( doPrint ) cout << " " << u;
    for ( auto v : adj[u] ) {
        if ( !vis[v] ) {
            dfs(v, true);
        }
    }
}

void work() {
    ll n;
    cin >> n;
    for ( int i = 0 ; i < n-1 ; i++ ) {
       ll a, b;
       cin >> a >> b;
       adj[a].pb(b);
       adj[b].pb(a);
    }
    // star tree
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( adj[i].size() == n-1 ) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    ll leaf = -1;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( adj[i].size() == 1 ) {
            leaf = i;
            break;
        }
    }
    cout << adj[leaf][0] << " " << leaf;
    vis[leaf] = true;
    dfs(adj[leaf][0], false);
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
