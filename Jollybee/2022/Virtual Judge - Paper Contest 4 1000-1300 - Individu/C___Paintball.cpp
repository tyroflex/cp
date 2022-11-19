//  C - Paintball

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

bool dfs( ll a, ll L, vector<vector<ll>>& g, vector<ll>& btoa, vector<ll>& A, vector<ll>& B ) {
    if ( A[a] != L ) return false;
    A[a] = -1;
    for ( ll b : g[a] ) if ( B[b] == L + 1 ) {
            B[b] = 0;
            if ( btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B) )
                return btoa[b] = a, 1;
        }
    return false;
}

ll hopcroftKarp(vector<vector<ll>>& g, vector<ll>& btoa) {
    ll res = 0;
    vector<ll> A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(all(A), 0);
        fill(all(B), 0);
        cur.clear();
        for ( ll a : btoa) if(a != -1) A[a] = -1;
        for ( ll a = 0; a < g.size() ; a++ ) if ( A[a] == 0 ) cur.pb(a);
        for ( ll lay = 1;; lay++ ) {
            bool islast = false;
            next.clear();
            for ( ll a : cur ) for ( ll b : g[a]) {
                    if (btoa[b] == -1) {
                        B[b] = lay;
                        islast = true;
                    }
                    else if (btoa[b] != a && !B[b]) {
                        B[b] = lay;
                        next.push_back(btoa[b]);
                    }
                }
            if (islast) break;
            if (next.empty()) return res;
            for ( ll a : next) A[a] = lay;
            cur.swap(next);
        }
        for ( ll a = 0 ; a < g.size() ; a++ ) res += dfs(a, 0, g, btoa, A, B);
    }
}

// Notes:
// Usage is vector<ll> btoa(m, -1); HopcroftKarp(g, btoa);
// G is the list of neighbors from the left partitions.

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
        adj[b].pb(a);
    }
    vector<ll> btoa(n+1, -1);
    ll ans = hopcroftKarp(adj, btoa);
    if ( ans != n ) {
        cout << "Impossible" << endl;
    } else {
        for ( int i = 1 ; i <= n ; i++ ) {
            cout << btoa[i] << endl;
        }
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
