//  M - Mex and Cards

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

using ll = long long int;
const ll inf = 1e18;

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0;
    ll minval = inf, sumval = 0, maxval = -inf;

    Node(ll lo, ll hi) : lo(lo), hi(hi) {}

    Node(vector<ll> &v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            sumval = l->sumval + r->sumval;
            maxval = max(l->maxval, r->maxval);
            minval = min(l->minval, r->minval);
        } else {
            sumval = maxval = minval = v[lo];
        }
    }

    ll sumquery(ll L, ll R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return sumval;
        push();
        return l->sumquery(L, R) + r->sumquery(L, R);
    }

    ll maxquery(ll L, ll R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return maxval;
        push();
        return max(l->maxquery(L, R), r->maxquery(L, R));
    }

    ll minquery(ll L, ll R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return minval;
        push();
        return min(l->minquery(L, R), r->minquery(L, R));
    }

    void set(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            sumval = (hi - lo) * x;
            minval = x;
            maxval = x;
            madd = 0;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            sumval = l->sumval + r->sumval;
            maxval = max(l->maxval, r->maxval);
            minval = min(l->minval, r->minval);
        }
    }

    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            sumval += (hi - lo) * x;
            minval += x;
            maxval += x;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            sumval = l->sumval + r->sumval;
            maxval = max(l->maxval, r->maxval);
            minval = min(l->minval, r->minval);
        }
    }

    void push() {
        if (!l) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }

    ll walk( ll x, ll left, ll right ) {
        ll ans = 0;
        while ( left <= right ) {
            ll middle = left + ( right - left ) / 2;
            if ( minquery(0, middle+1) >= x ) {
                ans = max(ans, middle);
                left = middle+1;
            } else {
                right = middle-1;
            }
        }
        return ans;
    }
};


void work() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> d[i];
    }
    vector<ll> mn(n);
    mn[0] = d[0];
    for ( int i = 1 ; i < n ; i++ ) {
        mn[i] = min(d[i], mn[i-1]);
    }
    Node valtree = Node(d, 0, n+5);
    Node mintree = Node(mn, 0, n+5);
    cout << mintree.sumquery(0, n) << endl;
    ll q;
    cin >> q;
    while ( q-- ) {
        ll a, b;
        cin >> a >> b;
        if ( a == 1 ) {
            if ( b == 0 ) {
                // 0 will always be the first.
                valtree.add(b, b+1, 1);
                ll target = valtree.walk(valtree.minquery(b, b+1), 0, n);
//                cout << target << endl;
                mintree.add(0, target+1, 1);
            }
            else if ( mintree.sumquery(b-1, b) != mintree.sumquery(b, b+1) ) {
                // if previous min is different.
                // this update will affect something.
                valtree.add(b, b+1, 1);
                ll target = valtree.walk(valtree.minquery(b, b+1), 0, n);
//                cout << target << endl;
                mintree.add(b, target+1, 1);
            }
            else {
                // if the previous min is the same as the current min,
                // then this update will not affect any of the min.
                valtree.add(b, b+1, 1);
            }
        } else {
            if ( valtree.sumquery(b, b+1) == mintree.minquery(b, b+1) ) {
                // if the current min is the same as the current value.
                // this update will affect something.
                ll target = valtree.walk(valtree.minquery(b, b+1), 0, n);
//                cout << target << endl;
                valtree.add(b, b+1, -1);
                mintree.add(b, target+1, -1);
            } else {
                // if the current min is not the same as the current value
                // this update affect nothing but itself.
                valtree.add(b, b+1, -1);
            }
        }
        cout << mintree.sumquery(0, n) << endl;
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
