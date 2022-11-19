//  Inversion Count
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

// Usage example:
// Tree<ll> t;
// t.order_of_key(val) returns the number of elements in t strictly less than val
// t.find_by_order(k) returns an iterator to the k-th largest element (counting from zero)
// t.join(t1, t2) joins t1 and t2 into t, t1 and t2 are empty afterwards
// t.split(t1, t2, val) splits t into t1 and t2, t1 contains all elements in t
// strictly less than val, t2 contains all elements in t greater than or equal to val

void work() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    rep(i, 0, n) cin >> d[i];
    Tree<pair<ll, ll>> t;
    ll ans = 0;
    rep(i, 0, n) {
        t.insert({d[i], i});
        ans += (ll)(i - t.order_of_key({d[i], i}));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while ( t-- ) work();
    return 0;
}
