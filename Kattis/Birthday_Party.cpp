//  Birthday Party

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


class BridgeFind {
    ll n, timer;
    vector<vector<ll>> adj;
    vector<bool> visited;
    vector<ll> tin, low;
    set<pair<ll, ll>> bridges;

public:
    BridgeFind( ll n ) : n(n), adj(n) {}
    BridgeFind( ll n, vector<vector<ll>> &adj ) : n(n), adj(adj) {}

    void dfs( ll v, ll p = -1 ) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        for ( ll to : adj[v] ) {
            if ( to == p ) continue;
            if ( visited[to] ) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if ( low[to] > tin[v] ) {
                    bridges.insert({v, to});
                }
            }
        }
    }

    bool isBridge( ll a, ll b ) {
        if ( bridges.find({a, b}) != bridges.end() ) return true;
        if ( bridges.find({b, a}) != bridges.end() ) return true;
        return false;
    }

    bool hasBridge() {
        return !bridges.empty();
    }

    void find() {
        timer = 0;
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        for ( int i = 0 ; i < n ; i++ ) {
            if ( !visited[i] ) {
                dfs(i);
            }
        }
    }

};

bool work() {
    ll n, m;
    cin >> n >> m;
    if ( n == 0 && m == 0 ) return false;
    vector<vector<ll>> adj(n+1);
    while ( m-- ) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    BridgeFind bf = BridgeFind(n, adj);
    bf.find();
    if ( bf.hasBridge() ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool res = true;
    while ( res ) res = work();
    return 0;
}
