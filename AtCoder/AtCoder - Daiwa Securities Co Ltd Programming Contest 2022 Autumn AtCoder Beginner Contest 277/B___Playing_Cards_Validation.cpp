//  B - Playing Cards Validation

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

set<char> fi = {'H', 'D', 'C', 'S'};
set<char> se = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

void work() {
    ll n;
    cin >> n;
    set<string> st;
    string s;
    while ( n-- ) {
        cin >> s;
        if ( fi.find(s[0]) == fi.end() || se.find(s[1]) == se.end() ) {
            cout << "No" << endl;
            return;
        }
        if ( st.find(s) != st.end() ) {
            cout << "No" << endl;
            return;
        }
        st.insert(s);
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
//    cin >> t;
    while ( t-- ) work();
    return 0;
}