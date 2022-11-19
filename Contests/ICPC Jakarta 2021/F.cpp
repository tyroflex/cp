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

const ll MAXN = 100001;
const ll MAXA = 1000001;
ll n;
vector<ll> d(MAXN);
vector<vector<ll>> pfactor(MAXN);
vector<unordered_map<ll, ll>> gcds(MAXN);
vector<vector<ll>> adj(MAXN);
vector<ll> vis(MAXN, 0);
vector<ll> indegree(MAXN, 0);
vector<ll> spf(MAXA);
vector<ll> primes;

void precompute() {
    vector<bool> isPrime(MAXA, true);
    for ( int i = 0 ; i < MAXA ; i++ ) {
        spf[i] = i;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    spf[2] = 2;
    for ( int i = 2*2 ; i < MAXA ; i += 2 ) {
        isPrime[i] = false;
        spf[i] = 2;
    }
    for ( int i = 3 ; i * i < MAXA ; i += 2 ) {
        if ( isPrime[i] ) {
            for ( int j = i*i ; j < MAXA ; j += i ) {
                isPrime[j] = false;
                spf[j] = i;
            }
        }
    }
    for ( int i = 2 ; i < MAXA ; i++ ) {
        if ( isPrime[i] ) primes.pb(i);
    }
}

void work() {
    cin >> n;
    ll ans = 0;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> d[i];
        set<ll> pfs;
        while ( d[i] != 1 ) {
            ll p = spf[d[i]];
            d[i] /= p;
            pfs.insert(p);
        }
        for ( ll pf : pfs ) {
            pfactor[i].pb(pf);
            gcds[i][pf] += 1;
            ans = 1;
        }
    }
    for ( int i = 1 ; i < n ; i++ ) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        indegree[a]++;
        indegree[b]++;
    }
    queue<ll> q;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( indegree[i] == 1 ) q.push(i);
    }
    while ( !q.empty() ) {
        ll now = q.front();
        q.pop();
        if ( !vis[now] ) {
            vis[now] = true;
            // find all the visited nodes connected to this.
            for ( ll v : adj[now] ) {
                if ( vis[v] ) {
                    for ( ll pf : pfactor[now] ) {
                        gcds[now][pf] += gcds[v][pf];
                        ans = max(ans, gcds[now][pf]);
                    }
                }
                if ( !vis[v] ) {
                    indegree[v]--;
                    if ( indegree[v] == 1 ) q.push(v);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    precompute();
//    cin >> t;
    while ( t-- ) work();
    return 0;
}