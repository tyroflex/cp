//
// Created by Tyrone Matthew on 11/7/2022.
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

using ll = long long int;
const ll inf = LLONG_MAX;

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mflip = 0;
    ll sumval = 0;

    Node(ll lo, ll hi) : lo(lo), hi(hi) {}

    Node(vector<ll> &v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            sumval = l->sumval + r->sumval;
        } else {
            sumval = v[lo];
        }
    }

    ll sumquery(ll L, ll R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return sumval;
        push();
        return l->sumquery(L, R) + r->sumquery(L, R);
    }

    // only use when the content of the tree is guaranteed
    // to be a binary string 0/1
    void flip(ll L, ll R) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if ( mflip ) mflip = 0;
            else mflip = 1;
            sumval = (hi - lo) - sumval;
        } else {
            push(), l->flip(L, R), r->flip(L, R);
            sumval = l->sumval + r->sumval;
        }
    }

    void push() {
        if (!l) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if ( mflip ) {
            l->flip(lo, hi); r->flip(lo, hi); mflip = 0;
        }
    }
};

void work() {
    ll n, m;
    cin >> n >> m;
    Node segtree = Node(1, n+1);
    while ( m-- ) {
        ll c, l, r;
        cin >> c >> l >> r;
        if ( c == 0 ) segtree.flip(l, r+1);
        else cout << segtree.sumquery(l, r+1) << endl;
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