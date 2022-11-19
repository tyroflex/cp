//
// Created by Tyrone Matthew on 11/16/2022.
//
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

struct Edge {
    ll weight, a, b;
    Edge(){}
    Edge(ll weight, ll a, ll b) : weight(weight), a(a), b(b) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct UF {
    vector<ll> e;
    UF(ll n) : e(n, -1) {}
    bool sameSet(ll a, ll b) { return find(a) == find(b); }
    ll size(ll x) { return -e[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

struct UFNoSize {
    vector<ll> par;
    UFNoSize(ll n) : par(n, -1) {
        for ( int i = 0 ; i < n ; i++ ) {
            par[i] = i;
        }
    }
    ll find(ll x) {
        if ( par[x] == x ) return x;
        else return par[x] = find(par[x]);
    }
    void join(ll a, ll b) {
        a = find(a), b = find(b);
        par[b] = a;
    }
};

template<class T>
struct RMQ {
    vector<vector<T>> jmp;

    RMQ(const vector<T> &V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k]))jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }

    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    ll T = 0;
    vector<ll> time, path, ret;
    RMQ<ll> rmq;
    LCA(vector<vector<ll>>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vector<ll>>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
                path.push_back(v), ret.push_back(time[v]);
                dfs(C, y, v);
            }
    }
    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
};

void dfs( const vector<vector<ll>>& adj, ll cur, vector<ll>& par, vector<ll>& vis ) {
    vis[cur] = true;
    for ( ll child : adj[cur] ) {
        if ( !vis[child] ) {
            par[child] = cur;
            dfs(adj, child, par, vis);
        }
    }
}

const ll MAXN = 100000;
ll n, m;
vector<ll> height(MAXN);
vector<Edge> edges;

void work() {
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++ ) cin >> height[i];
    while ( m-- ) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        edges.pb(Edge(abs(height[a]-height[b]), a, b));
    }
    sort(all(edges));
//    for ( Edge e : edges ) {
//        cout << e.a+1 << " " << e.b+1 << " " << e.weight << endl;
//    }
    UF uf(n);
    // set up the minimum spanning tree
    // adjacency list
    vector<Edge> unused;
    vector<vector<ll>> adj(n);
    for ( Edge e : edges ) {
        if ( !uf.sameSet(e.a, e.b) ) {
            uf.join(e.a, e.b);
            adj[e.a].pb(e.b);
            adj[e.b].pb(e.a);
        } else {
            unused.pb(e);
        }
    }
    // DEBUG TREE
//    for ( int i = 0 ; i < n ; i++ ) {
//        cout << i << ":";
//        for ( ll child : adj[i] ) {
//            cout << " " << child;
//        }
//        cout << endl;
//    }
    vector<ll> ans(n, 1e18);
    // construct LCA
    LCA lca(adj);
    vector<ll> par(n, -1);
    vector<ll> vis(n, false);
    par[0] = -1;
    dfs(adj, 0, par, vis);
//    for ( int i = 0 ; i < n ; i++ ) {
//        cout << par[i] << " ";
//    }
//    cout << endl;
    // group them up 'O')9
    UFNoSize uf2(n);
    // try adding each edge back in
    for ( Edge e : unused ) {
        ll target = lca.lca(e.a, e.b);
//        cout << e.a << " " << e.b << " " << target << endl;
        ll it = e.a;
        while ( it != target && lca.lca(it, target) == target ) {
            ans[it] = min(ans[it], e.weight);
            ll big = uf2.find(par[it]);
            par[it] = big;
            // let our node right now join the parent.
            uf2.join(big, it);
            it = big;
        }
        it = e.b;
        while ( it != target && lca.lca(it, target) == target ) {
            ans[it] = min(ans[it], e.weight);
            ll big = uf2.find(par[it]);
            par[it] = big;
            // let our node right now join the parent.
            uf2.join(big, it);
            it = big;
        }
        ans[target] = min(ans[target], e.weight);
        if ( target != 0 ) {
            ll big = uf2.find(par[target]);
            par[target] = big;
            uf2.join(big, target);
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        cout << ( ans[i] == 1e18 ? -1 : ans[i] );
        if ( i < n-1 ) cout << " ";
        else cout << endl;
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