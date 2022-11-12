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

void precompute() {

}

using ll = long long int;
const ll inf = 1e18;

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi;
    ll maxval = -inf, index = inf;

    Node(ll lo, ll hi) : lo(lo), hi(hi) {}

    Node(vector<ll> &v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            maxval = max(l->maxval, r->maxval);
        } else {
            maxval = v[lo];
        }
    }

    pair<ll, ll> maxquery(ll L, ll R) {
        if (R <= lo || hi <= L) return {-inf, inf};
        if (L <= lo && hi <= R) return {maxval, index};
        push();
        pair<ll, ll> lc = l->maxquery(L, R);
        pair<ll, ll> rc = r->maxquery(L, R);
        if ( lc.first == rc.first ) {
            return rc;
        }
        else if ( lc.first > rc.first ) {
            return lc;
        }
        else {
            return rc;
        }
    }

    void set(ll L, ll R, ll x, ll idx) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            maxval = x;
            index = idx;
            if ( x >= maxval ) {
                maxval = x;
                index = idx;
            }
        } else {
            push(), l->set(L, R, x, idx), r->set(L, R, x, idx);
            if ( l->maxval == r->maxval ) {
                index = r->index;
            } else if ( l->maxval > r->maxval ) {
                index = l->index;
            } else {
                index = r->index;
            }
            maxval = max(l->maxval, r->maxval);
        }
    }

    void push() {
        if (!l) {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
    }
};


void work() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> d[i];
    }
    vector<ll> prev(n, -1);
    Node lengthtree(-1e7, 1e7);
    for ( int i = 0 ; i < n ; i++ ) {
        // find the longest subsequences behind this.
        pair<ll, ll> l = lengthtree.maxquery(-1e7, d[i]+1);
        // if this returns nothing then there's no smaller values here.
        if ( l.first == -inf && l.second == inf ) {
            prev[i] = -1;
            lengthtree.set(d[i], d[i]+1, 1, i);
        } else {
            // we use the previous number's index.
            prev[i] = l.second;
            // update this number's value to reflect current.
            lengthtree.set(d[i], d[i]+1, l.first+1, i);
        }
    }
    // finding the longest subsequence.
    pair<ll, ll> mx = lengthtree.maxquery(-1e7, 1e7);
    vector<ll> ans;
    cout << "Panjang maksimal adalah " << mx.first << endl;
    do {
        ans.pb(d[mx.second]);
        mx.second = prev[mx.second];
    } while ( mx.second != -1 );
    reverse(all(ans));
    for ( int i = 0 ; i < ans.size() ; i++ ) {
        cout << ans[i];
        if ( i < ans.size()-1 ) cout << " => ";
        else cout << endl;
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