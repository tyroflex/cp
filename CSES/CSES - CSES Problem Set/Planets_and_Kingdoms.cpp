//  Planets and Kingdoms

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

vector<ll> val, comp, z, cont;
ll Time, ncomps;
template<class G, class F> ll dfs(ll j, G& g, F& f) {
    ll low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j]) if (comp[e] < 0)
            low = min(low, val[e] ?: dfs(e,g,f));
    if (low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}

template<class G, class F> void scc(G& g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

// SCC
// comp contains the component number of each node
// ncomps contains the number of components

// Extra Info (in-process data):
// val contains the time of each node
// z contains the stack of nodes
// cont contains the current component

void precompute() {

}

void work() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n+1);
    for ( int i = 0 ; i < m ; i++ ) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    vector<ll> tst;
    scc(adj, [&](vector<ll>& v) {});
    cout << ncomps-1 << endl;
    for ( int i = 1 ; i < comp.size() ; i++ ) {
        cout << comp[i];
        if ( i < comp.size() - 1 ) cout << " ";
        else cout << endl;
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
