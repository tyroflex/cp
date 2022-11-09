//
// Created by Tyrone Matthew on 11/4/2022.
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

using ll = long long int;
const ll inf = LLONG_MAX;

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
};

void precompute() {

}

void work() {
    Node segtree = Node(0, 1000000001);
    segtree.set(0, 1000000001, 0);
    ll n;
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        ll x, y;
        cin >> x >> y;
        segtree.add(x, y+1, 1);
    }
    ll q;
    cin >> q;
    while ( q-- ) {
        ll l, r;
        cin >> l >> r;
        cout << segtree.maxquery(l, r+1) << endl;
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