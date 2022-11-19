//  Problem 3. Moocast

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

vector<pll> cows;
vector<ll> power;
vector<bool> vis;

ll distance( const pll&a, const pll &b ) {
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

bool canReach( const ll& p, const ll& dist ) {
    return (p*p) >= dist;
}

void dfs( ll u, ll& score ) {
    vis[u] = true;
    score++;
    for ( int i = 0 ; i < cows.size() ; i++ ) {
        if ( !vis[i] && canReach(power[u], distance(cows[u], cows[i])) ) {
            dfs(i, score);
        }
    }
}

void work() {
    ll n;
    cin >> n;
    cows = vector<pll>(n);
    power = vector<ll>(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> cows[i].first >> cows[i].second >> power[i];
    }
    ll ans = 0;
    for ( int i = 0 ; i < n ; i++ ) {
        ll score = 0;
        vis = vector<bool>(n, false);
        dfs(i, score);
        ans = max(ans, score);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
//    cin >> t;
    while ( t-- ) work();
    return 0;
}