//
// Created by Tyrone Matthew on 11/7/2022.
//
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define endl '\n'
#define all(x) (x).begin(), (x).end()

struct Node {
    Node *l, *r;
    ll lo, hi, madd, sumval;

    Node(ll lo, ll hi) : lo(lo), hi(hi) {}

    Node(vector<ll> &v, ll lo, ll hi) : lo(lo), hi(hi) {
        l = 0, r = 0;
        madd = 0; sumval = 0;
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

    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd += x;
            sumval += (hi - lo) * x;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            sumval = l->sumval + r->sumval;
        }
    }

    void push() {
        if (!l) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

void work() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for ( ll i = 1; i <= n; i++ ) cin >> v[i];
    Node segtree = Node(v, 1, n+1);
    while ( q-- ) {
        char c;
        cin >> c;
        if ( c == 'Q' ) {
            ll l, r;
            cin >> l >> r;
            cout << segtree.sumquery(l, r+1) << endl;
        } else {
            ll l, r, x;
            cin >> l >> r >> x;
            segtree.add(l, r+1, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}