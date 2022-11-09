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

vector<bool> isPrime(1000001, true);

using ll = long long int;
const ll inf = LLONG_MAX;

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf;
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
            if ( isPrime[v[lo]] ) sumval = maxval = minval = 1;
            else sumval = maxval = minval = 0;
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
            if ( isPrime[x] ) sumval = maxval = minval = (hi - lo);
            else sumval = maxval = minval = 0;
        } else {
            push(), l->set(L, R, x), r->set(L, R, x);
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
    }
};



void precompute() {
    isPrime[0] = isPrime[1] = false;
    for ( int i = 2 ; i * i <= 1000000 ; i++ ) {
        if ( isPrime[i] ) {
            for ( int j = i*i ; j <= 1000000 ; j += i ) {
                isPrime[j] = false;
            }
        }
    }
}


void work() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> v[i];
    }
    Node segtree = Node(v, 1, n+1);
    while ( q-- ) {
        ll c, l, r;
        cin >> c >> l >> r;
        if ( c == 0 ) {
            ll x;
            cin >> x;
            segtree.set(l, r+1, x);
        } else {
            cout << segtree.sumquery(l, r+1) << endl;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    ll t = 1;
    cin >> t;
    for ( int i = 1 ; i <= t ; i++ ) {
        cout << "Case " << i << ":" << endl;
        work();
    }
    return 0;
}