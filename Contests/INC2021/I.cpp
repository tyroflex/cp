//
// Created by Tyrone Matthew on 11/11/2022.
//
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

void precompute() {

}

struct Dest {
    ll dist, group, index;
    Dest(){}
    Dest(ll dist, ll group, ll index) : dist(dist), group(group), index(index) {}
};

struct CompareDest {
    bool operator()(const Dest& a, const Dest& b) {
        return a.dist > b.dist;
    }
};

void work() {
    ll n, m;
    cin >> n >> m;
    vector<vector<Dest>> adj(n+2);
    priority_queue<Dest, vector<Dest>, CompareDest> pq;
    while ( m-- ) {
        ll a, b, p, t;
        cin >> a >> b >> p >> t;
        adj[a].pb(Dest(t, p, b));
        adj[b].pb(Dest(t, p, a));
    }
//    adj[n].pb(Dest(0, 1, n+1));
    vector<bool> vis(n+2, false);
    pq.push(Dest(0, 1, 1));
//    ll ans = LLONG_MAX;
    while ( !pq.empty() ) {
        Dest now = pq.top();
        pq.pop();
        vis[now.index] = true;
        if ( now.index == n ) {
//            ans = min(ans, now.dist);
            cout << now.dist << endl;
            return;
        }
        for ( Dest next : adj[now.index] ) {
            if ( vis[next.index] ) continue;
            if ( next.index == n ) {
                pq.push(Dest(now.dist + next.dist + abs(now.group-next.group) + abs(next.group-1), next.group, next.index));
            } else {
                pq.push(Dest(now.dist + abs(now.group-next.group) + next.dist, next.group, next.index));
            }
        }
    }
//    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}