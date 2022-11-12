//
// Created by Tyrone Matthew on 11/12/2022.
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

using ll = long long int;
const ll inf = 1e18;

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0;
    ll index;
    ll minval = inf;

    Node(ll lo, ll hi) : lo(lo), hi(hi) {}

    Node(vector<ll> &v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            minval = min(l->minval, r->minval);
            if ( l->minval == r->minval ) index = l->index;
            else if ( l->minval < r->minval ) index = l->index;
            else index = r->index;
        } else {
            index = lo;
            minval = v[lo];
        }
    }

    pair<ll, ll> minquery(ll L, ll R) {
        if (R <= lo || hi <= L) return {inf, inf};
        if (L <= lo && hi <= R) return {minval, index};
        push();
        pair<ll, ll> lc = l->minquery(L, R);
        pair<ll, ll> rc = r->minquery(L, R);
        if ( lc.first == rc.first ) return lc;
        else if ( lc.first < rc.first ) return lc;
        else return rc;
    }

    void set(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            minval = x;
            madd = 0;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            minval = min(l->minval, r->minval);
        }
    }

    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            minval += x;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
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
};

void precompute() {

}

void work() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> d[i];
    }
    Node segtree = Node(d, 0, n);
    ll q;
    cin >> q;
    while ( q-- ) {
        ll a, b;
        cin >> a >> b;
        pair<ll, ll> query = segtree.minquery(a, b+1);
        cout << query.second << endl;
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