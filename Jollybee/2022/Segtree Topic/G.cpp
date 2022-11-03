//
// Created by Tyrone Matthew on 11/3/2022.
//
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(x) (x).begin(), (x).end()

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using oset = tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

void precompute() {

}

void work() {
    ll q;
    cin >> q;
    oset os;
    while ( q-- ) {
        char ops;
        ll in;
        cin >> ops >> in;
        if ( ops == 'I' ) os.insert(in);
        else if ( ops == 'D' ) os.erase(in);
        else if ( ops == 'K' ) {
            if ( in > os.size() ) cout << "invalid" << endl;
            else cout << *(os.find_by_order(in-1)) << endl;
        } else cout << os.order_of_key(in) << endl;
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