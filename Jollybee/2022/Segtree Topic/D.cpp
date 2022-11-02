//
// Created by Tyrone Matthew on 11/2/2022.
//

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(x) (x).begin(), (x).end()

using ll = long long int;
const ll inf = LLONG_MAX;

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0, val = 0;

    Node(ll lo, ll hi) : lo(lo), hi(hi) {}

    Node(vector<ll> &v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = l->val + r->val;
        } else val = v[lo];
    }

    ll query(ll L, ll R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }

    void set(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            mset = x;
            val = ((hi - lo) * x);
            madd = 0;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }

    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += ((hi - lo) * x);
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
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
    ll n, c;
    cin >> n >> c;
    Node segtree = Node(0, n+1);
    while ( c-- ) {
        ll cmd;
        cin >> cmd;
        if ( cmd == 0 ) {
            ll p, q, v;
            cin >> p >> q >> v;
            segtree.add(p, q+1, v);
        } else {
            ll p, q;
            cin >> p >> q;
            cout << segtree.query(p, q+1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while ( t-- ) work();
    return 0;
}