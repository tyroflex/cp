//
// Created by Tyrone Matthew on 11/4/2022.
//

// Note:
// Problem has 10 Testcases, use one Segment Tree and just update
// the segment tree's values one by one on each testcase
// otherwise MLE.

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
const int inf = INT_MAX;

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0;
    int minval = inf, sumval = 0, maxval = -inf;

    Node(int lo, int hi) : lo(lo), hi(hi) {}

    Node(vector<int> &v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            sumval = l->sumval + r->sumval;
            maxval = max(l->maxval, r->maxval);
            minval = min(l->minval, r->minval);
        } else {
            sumval = maxval = minval = v[lo];
        }
    }

    int sumquery(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return sumval;
        push();
        return l->sumquery(L, R) + r->sumquery(L, R);
    }

    int maxquery(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return maxval;
        push();
        return max(l->maxquery(L, R), r->maxquery(L, R));
    }

    int minquery(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return minval;
        push();
        return min(l->minquery(L, R), r->minquery(L, R));
    }

    void set(int L, int R, int x) {
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

    void add(int L, int R, int x) {
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
            int mid = lo + (hi - lo) / 2;
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

Node segtree = Node(0, 100000);

void work() {
    string s;
    cin >> s;
    for ( int i = 0 ; i < s.length() ; i++ ) {
        segtree.set(i, i+1, (s[i]-'0'));
    }
    int q;
    cin >> q;
    while ( q-- ) {
        char cmd;
        cin >> cmd;
        if ( cmd == 'I' ) {
            int l, r;
            cin >> l >> r;
            segtree.add(l-1, r, 1);
        } else {
            int k;
            cin >> k;
            cout << segtree.sumquery(k-1, k) % 2 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    for ( int i = 1 ; i <= t ; i++ ) {
        cout << "Case " << i << ":" << endl;
        work();
    }
    return 0;
}