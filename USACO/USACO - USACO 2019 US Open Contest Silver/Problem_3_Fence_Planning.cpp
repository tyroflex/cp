//  Problem 3. Fence Planning

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

struct UF {
    vector<ll> e;
    UF(ll n) : e(n, -1) {}
    bool sameSet(ll a, ll b) { return find(a) == find(b); }
    ll size(ll x) { return -e[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void work() {
    ll n, m;
    cin >> n >> m;
    vector<pll> cows(n+1);
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> cows[i].first >> cows[i].second;
    }
    UF dsu(n+1);
    while ( m-- ) {
        ll a, b;
        cin >> a >> b;
        dsu.join(a, b);
    }
    vector<ll> maxx(n+1, -1e9);
    vector<ll> minx(n+1, 1e9);
    vector<ll> maxy(n+1, -1e9);
    vector<ll> miny(n+1, 1e9);
    for ( int i = 1 ; i <= n ; i++ ) {
        ll g = dsu.find(i);
//        cout << g << endl;
        maxx[g] = max(maxx[g], cows[i].first);
        minx[g] = min(minx[g], cows[i].first);
        maxy[g] = max(maxy[g], cows[i].second);
        miny[g] = min(miny[g], cows[i].second);
    }
    ll smallestArea = 1e18;
    for ( int i = 1 ; i <= n ; i++ ) {
        ll area = (2*(maxx[i]-minx[i])) + (2*(maxy[i]-miny[i]));
        if ( area >= 0 ) smallestArea = min(smallestArea, area);
    }
    cout << smallestArea << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
//    cin >> t;
    while ( t-- ) work();
    return 0;
}
